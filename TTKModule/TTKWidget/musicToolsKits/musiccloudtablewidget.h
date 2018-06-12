#ifndef MUSICCLOUDTABLEWIDGET_H
#define MUSICCLOUDTABLEWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2018 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include "musicclouddataitem.h"
#include "musicdownloadabstracttablewidget.h"

/*! @brief The class of the cloud shared song download table widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_TOOL_EXPORT MusicCloudDownloadTableWidget : public MusicDownloadAbstractTableWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicCloudDownloadTableWidget)
public:
    /*!
     * Object contsructor.
     */
    explicit MusicCloudDownloadTableWidget(QWidget *parent = 0);

    virtual ~MusicCloudDownloadTableWidget();

protected:
    /*!
     * Create item by index and name and size and time.
     */
    virtual void createItem(int index, const MusicDownloadRecord &record) override;

};


/*! @brief The class of the cloud shared song upload table widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_TOOL_EXPORT MusicCloudUploadTableWidget : public MusicDownloadAbstractTableWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicCloudUploadTableWidget)
public:
    /*!
     * Object contsructor.
     */
    explicit MusicCloudUploadTableWidget(QWidget *parent = 0);

public Q_SLOTS:
    /*!
     * Upload file error occurred.
     */
    void uploadFileError(const MusicCloudDataItem &item);

protected:
    /*!
     * Create item by index and name and size and time.
     */
    virtual void createItem(int index, const MusicDownloadRecord &record) override;

};

#endif // MUSICCLOUDTABLEWIDGET_H
