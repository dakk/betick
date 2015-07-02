/*
 * Copyright (C) 2012-2015  Gessa Davide (gessadavide@gmail.com)
 * Copyright (C) 2012-2015  Casalinuovo Dario (b.vitruvio@gmail.com)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */
/* 
 * Authors:
 *		Dario Casalinuovo, barrett666@gmail.com
 */
#ifndef BETICK_SETTINGS_H
#define BETICK_SETTINGS_H

#include <File.h>
#include <Message.h>
#include <Path.h>
#include <String.h>

class Settings : public BMessage {
public:
						Settings(BPath path);
virtual					~Settings();

		status_t		OpenSettings();

		status_t		ReadSetting(const char* name, BString* string);
		status_t		ReadSetting(const char* name, int32* setting);
		status_t		ReadSetting(const char* name, bool* setting);

		status_t		WriteSetting(const char* name, const char* string);
		status_t		WriteSetting(const char* name, int32 setting);
		status_t		WriteSetting(const char* name, bool setting);
		
		status_t		ReplaceSetting(const char* name, const char* string);
		status_t		ReplaceSetting(const char* name, int32 setting);
		status_t		ReplaceSetting(const char* name, bool setting);

		status_t		RemoveSetting(const char* name);

		status_t		FlattenSettings();
		
		status_t		DeleteSettings();
protected:
		BFile*			fSettingsFile;
		BPath			fSettingsPath;
}; 

#endif /* SETTINGS_H */
