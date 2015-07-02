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
#ifndef BETICK_SETTINGSVIEW_H
#define BETICK_SETTINGSVIEW_H

class BMenuBar;
class BMenu;
class BButton;
class BSlider;
class BTextControl;

const int32 MSG_DEFAULTS = 0xA1;
const int32 MSG_REVERT	 = 0xA2;


class SettingsView : public BView {
public:
							SettingsView();
							~SettingsView();
			void			AttachedToWindow();	
	virtual	void			MessageReceived(BMessage* message);

private:
			BTextControl*	fTicSoundEntry;
			BTextControl*	fTocSoundEntry;
			BButton*		fDefaultsButton;
			BButton*		fRevertButton;
};



#endif
