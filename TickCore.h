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
 *		Davide Gessa, dak.linux@gmail.com
 */
#ifndef BETICK_CORE_H
#define BETICK_CORE_H

class TickProducer;
class BMediaRoster;

const int32		DEFAULT_SPEED	=	60;
const int32		DEFAULT_VOLUME	=	80;

/**
 * Il core dell'applicazione
 */
class TickCore {
public:
						TickCore();
						~TickCore();

	status_t			InitCheck();
	status_t			Connect();
	status_t			Disconnect();
	void 				Stop();
	void 				Start();

	void 				SetSpeed(int32 speed);
	void 				SetMeter(int32 meter);
	void 				SetVolume(int32 volume);
	
	int32 				Speed();
	int32 				Meter();
	int32 				Volume();

private:
	int32 				fSpeed;
	int32 				fMeter;
	int32				fVolume;
	bool 				fRunning;

	status_t			fErr;
	BMediaRoster* 		fMediaRoster;
	TickProducer*		fTickProducer;
};


#endif
