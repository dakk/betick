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
 *		Barrett, barrett666@gmail.com
 */

#include <MediaEventLooper.h>
#include <MediaRoster.h>
#include <TimeSource.h>

#include "TickCore.h"
#include "TickProducer.h"


/*
 * Initialize the class with default values
 */
TickCore::TickCore()
	:
	fSpeed(DEFAULT_SPEED),
	fMeter(0),
	fVolume(DEFAULT_VOLUME),
	fRunning(false)
{
	fTickProducer = new TickProducer();
	Connect();
	
	
	fTickProducer->SetMeter(Meter());
	fTickProducer->SetSpeed(Speed());
}


/*
 * Destroy the class
 */
TickCore::~TickCore()
{
	Disconnect();
	delete fTickProducer;
}


// metodo per controllare eventuali errori interni
status_t
TickCore::InitCheck()
{
	return fErr;
}


// questo dovrebbe occuparsi di connettere i nodi
status_t
TickCore::Connect() 
{
	fMediaRoster = BMediaRoster::Roster(&fErr);
	if (fErr != B_OK || !fMediaRoster) {
		return fErr;
	}

	return fMediaRoster->RegisterNode(fTickProducer);
}


// disconnette i nodi
status_t
TickCore::Disconnect() 
{
	return fMediaRoster->UnregisterNode(fTickProducer);
}


/** Start the metronome */
void 
TickCore::Start()
{
	if (!fRunning) {
		fRunning = 1;	

		fMediaRoster->StartNode(fTickProducer->Node(), 
					fTickProducer->TimeSource()->Now() + 5000LL);
	}
}


/** Stop the metronome */
void 
TickCore::Stop()
{
	if (fRunning) {
		fRunning = 0;
		
		fMediaRoster->StopNode(fTickProducer->Node(), 0);
	}
}


void 
TickCore::SetSpeed(int32 s)
{
	if (s <= 500 && s > 1) {
		fSpeed = s;
		fTickProducer->SetSpeed(s);
	}
}


void 
TickCore::SetMeter(int32 m)
{
	if (m < 10 && m >= 0) {
		fMeter = m;
		fTickProducer->SetMeter(m);
	}
}


void 
TickCore::SetVolume(int32 v)
{
	if (v <= 100 && v >= 0) {
		fVolume = v;
	}
}


int32 
TickCore::Volume()
{
	return fVolume;	
}


int32
TickCore::Speed()
{
	return fSpeed;	
}


int32
TickCore::Meter()
{
	return fMeter;	
}
