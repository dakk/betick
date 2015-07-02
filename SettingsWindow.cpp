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
#include <Application.h>
#include <GroupLayout.h>
#include <Window.h>
#include <View.h>
#include "SettingsWindow.h"
#include "SettingsView.h"



SettingsWindow::SettingsWindow(BRect frame) 
	:
	BWindow(frame, "BeTick Settings", B_TITLED_WINDOW,
		B_NOT_ZOOMABLE)
{	
	SetLayout(new BGroupLayout(B_VERTICAL));

	fSettingsView = new SettingsView();
	GetLayout()->AddView(fSettingsView);
}


void
SettingsWindow::MessageReceived(BMessage* message)
{
	switch (message->what)
	{
		default:
			BWindow::MessageReceived(message);
	}

}



bool
SettingsWindow::QuitRequested()
{
	//delete fSettingsView;
	return true;
}

