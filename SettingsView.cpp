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
 *		Casalinuovo Dario, barrett666@gmail.com
 *		Davide Gessa, dak.linux@gmail.com
 */
#include <Application.h>
#include <Alert.h>
#include <Button.h>
#include <GroupLayout.h>
#include <GroupView.h>
#include <OS.h>
#include <Menu.h>
#include <MenuBar.h>
#include <MenuItem.h>
#include <Slider.h>
#include <TextControl.h>
#include <Window.h>
#include <View.h>
#include <Box.h>
#include <CheckBox.h>
#include <File.h>
#include <FindDirectory.h>
#include <Input.h>
#include <LayoutBuilder.h>
#include <SpaceLayoutItem.h>

#include "SettingsView.h"


SettingsView::~SettingsView()
{

}


SettingsView::SettingsView()
	:
	BView("SettingsView", B_WILL_DRAW, 0)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	
	// Main layout
	BGroupLayout* rootLayout = new BGroupLayout(B_VERTICAL);
	SetLayout(rootLayout);

	// Audiofile entry
	BGroupView* audioGroup = new BGroupView(B_HORIZONTAL);
	BBox* audioBox = new BBox("audiobox");
	audioBox->SetLabel("Audio files");

	BGroupLayout* audioLayout = new BGroupLayout(B_VERTICAL);
	audioLayout->SetInsets(10, audioBox->TopBorderOffset() * 2 + 10, 10, 10);
	audioBox->SetLayout(audioLayout);
	
	fTocSoundEntry = new BTextControl("Toc", "Toc", "audio/toc.wav",
		new BMessage(MSG_DEFAULTS), B_WILL_DRAW);

	fTocSoundEntry->SetDivider(70);
	fTocSoundEntry->SetAlignment(B_ALIGN_CENTER, B_ALIGN_CENTER);
		
	fTicSoundEntry = new BTextControl("Tic", "Tic", "audio/tic.wav", 
		new BMessage(MSG_DEFAULTS), B_WILL_DRAW);

	fTicSoundEntry->SetDivider(70);
	fTicSoundEntry->SetAlignment(B_ALIGN_CENTER, B_ALIGN_CENTER);

	audioLayout->AddView(fTicSoundEntry);
	audioLayout->AddView(fTocSoundEntry);
	audioGroup->GroupLayout()->AddView(audioBox);
	rootLayout->AddView(audioGroup);
	
	// Defaults and revert buttons
	BGroupView* buttonGroup = new BGroupView(B_HORIZONTAL);

	fDefaultsButton = new BButton("Defaults", new BMessage(MSG_DEFAULTS));						
	buttonGroup->GroupLayout()->AddView(fDefaultsButton);

	fRevertButton = new BButton("Revert", new BMessage(MSG_REVERT));							
	buttonGroup->GroupLayout()->AddView(fRevertButton);

	rootLayout->AddView(buttonGroup);
}

void
SettingsView::AttachedToWindow()
{
	fDefaultsButton->SetTarget(this);
	fRevertButton->SetTarget(this);
	fTicSoundEntry->SetTarget(this);
	fTocSoundEntry->SetTarget(this);	
	
	Window()->CenterOnScreen();
}


void
SettingsView::MessageReceived(BMessage *message)
{
	switch(message->what)
	{
		case MSG_REVERT:
		case MSG_DEFAULTS:
		default:
			BView::MessageReceived(message);
	}			
}


