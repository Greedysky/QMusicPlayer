/***************************************************************************
 * This file is part of the TTK qmmp plugin project
 * Copyright (C) 2015 - 2022 Greedysky Studio

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
 ***************************************************************************/

#ifndef SPEKUTILS_H
#define SPEKUTILS_H

inline int spek_max(int a, int b)
{
    return a > b ? a : b;
}

inline int spek_min(int a, int b)
{
    return a < b ? a : b;
}

// Compare version numbers, e.g. 1.9.2 < 1.10.0
int spek_vercmp(const char *a, const char *b);

#endif
