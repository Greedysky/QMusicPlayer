#include "musicdownloadtagdatarequest.h"
#include "musicdownloadsourcerequest.h"
#include "musicsettingmanager.h"

#include <QImage>

MusicDownloadTagDataRequest::MusicDownloadTagDataRequest(const QString &url, const QString &path, MusicObject::Download type, QObject *parent)
    : MusicDownloadDataRequest(url, path, type, parent)
{
    m_needUpdate = false;
}

void MusicDownloadTagDataRequest::setSongMeta(MusicSongMeta &meta)
{
    m_songMeta = std::move(meta);
}

void MusicDownloadTagDataRequest::startToDownload()
{
    if(m_file && (!m_file->exists() || m_file->size() < 4))
    {
        if(m_file->open(QIODevice::WriteOnly))
        {
            startRequest(m_url);
            disconnect(m_reply, SIGNAL(finished()), this, SLOT(downLoadFinished()));
            connect(m_reply, SIGNAL(finished()), this, SLOT(downLoadFinished()));
        }
        else
        {
            TTK_LOGGER_ERROR("The data file create failed");
            Q_EMIT downLoadDataChanged("The data file create failed");
            deleteAll();
        }
    }
}

void MusicDownloadTagDataRequest::downLoadFinished()
{
    bool save = (m_file != nullptr);
    MusicDownloadDataRequest::downLoadFinished();

    if(m_redirection)
    {
        return;
    }

    if(save)
    {
        MusicSemaphoreLoop loop;
        connect(this, SIGNAL(finished()), &loop, SLOT(quit()));

        MusicDownloadSourceRequest *d = new MusicDownloadSourceRequest(this);
        connect(d, SIGNAL(downLoadRawDataChanged(QByteArray)), SLOT(downLoadFinished(QByteArray)));
        d->startToDownload(m_songMeta.comment());
        loop.exec();
    }

    Q_EMIT downLoadDataChanged(mapCurrentQueryData());
    TTK_LOGGER_INFO("Data download has finished");
}

void MusicDownloadTagDataRequest::downLoadFinished(const QByteArray &bytes)
{
    MusicSongMeta meta;
    if(meta.read(m_savePath))
    {
        if(G_SETTING_PTR->value(MusicSettingManager::OtherWriteFileInfo).toBool())
        {
            meta.setTitle(m_songMeta.title());
            meta.setArtist(m_songMeta.artist());
            meta.setAlbum(m_songMeta.album());
            meta.setTrackNum(m_songMeta.trackNum());
            meta.setYear(m_songMeta.year());
        }

        if(G_SETTING_PTR->value(MusicSettingManager::OtherWriteAlbumCover).toBool())
        {
            if(bytes.isEmpty())
            {
                TTK_LOGGER_ERROR("Input byte data is empty");
            }
            else
            {
                meta.setCover(bytes);
            }
        }
        meta.save();
        TTK_LOGGER_INFO("Write tag has finished");
    }

    Q_EMIT finished();
}
