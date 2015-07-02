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
 *		Dario Casalinuovo
 */
#ifndef BETICK_VIEW_H
#define BETICK_VIEW_H

class BMenuBar;
class BMenu;
class BButton;
class BSlider;
class BTextControl;
class BRadioButton;
class TickCore;

const int32 MSG_SETTINGS			= 0x5;
const int32 MSG_EDIT				= 0x6;
const int32 MSG_ABOUT				= 0x7;
const int32 MSG_CLOSE				= 0x8;
const int32 MSG_START				= 0x9;
const int32 MSG_STOP				= 0x10;
const int32 MSG_VOLUME				= 0x11;
const int32 MSG_SPEED_SLIDER		= 0x12;
const int32 MSG_SPEED_ENTRY			= 0x13;
const int32 MSG_METER_ENTRY			= 0x14;
const int32 MSG_METER_RADIO			= 0x15;

/**
 * View del metronomo
 */
class TickView : public BView {
public:
							TickView();
							~TickView();
			void			AttachedToWindow();	
	virtual	void			MessageReceived(BMessage* message);

private:
			BMenuBar		*fMenuBar;
			BMenu			*fFileMenu;
			BMenu			*fEditMenu;
			BButton			*fStartButton;
			BButton			*fStopButton;
			BSlider			*fVolumeSlider;

			BRadioButton	*fMeterRadios[5];
			BTextControl	*fMeterEntry;

			BTextControl	*fSpeedEntry;
			BSlider			*fSpeedSlider;
			TickCore		*fTickCore;
};



#endif
