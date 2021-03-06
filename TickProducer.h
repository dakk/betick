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
 *		Barrett
 */
#ifndef BETICK_PRODUCER_H
#define BETICK_PRODUCER_H 1

#include <BufferProducer.h>
#include <MediaEventLooper.h>

class BMediaFile;
class BMediaTrack;

class TickProducer : public BBufferProducer, public BMediaEventLooper 
{
public:
						TickProducer();
						~TickProducer();
	
	// BMediaNode methods
	BMediaAddOn* 		AddOn(int32* internal_id) const;

	// BBufferProducer methods
	status_t 			FormatSuggestionRequested(media_type type,
													int32 quality,
													media_format* format);

	status_t 			FormatProposal(const media_source& output,
										media_format* format);

	status_t 			FormatChangeRequested(const media_source& source,
												const media_destination& destination,
												media_format* io_format,
												int32* _deprecated_);

	status_t 			GetNextOutput(int32* cookie,
										media_output* out_output);

	status_t 			DisposeOutputCookie(int32 cookie);

	status_t 			SetBufferGroup(const media_source& for_source,
										BBufferGroup* group);

	
	status_t 			GetLatency(bigtime_t* out_latency);

	status_t 			PrepareToConnect(const media_source& what,
										 const media_destination& where,
										 media_format* format,
										 media_source* out_source,
										 char* out_name);

	void 				Connect(status_t error, 
								const media_source& source,
								const media_destination& destination,
								const media_format& format,
								char* io_name);

	void 				Disconnect(const media_source& what,
									const media_destination& where);

	void 				LateNoticeReceived(const media_source& what,
											bigtime_t how_much,
											bigtime_t performance_time);

	void 				EnableOutput(const media_source & what,
										bool enabled,
										int32* _deprecated_);

	status_t 			SetPlayRate(int32 numer, int32 denom);

	status_t 			HandleMessage(int32 message,
										const void* data,
										size_t size);

	void 				AdditionalBufferRequested(const media_source& source,
													media_buffer_id prev_buffer,
													bigtime_t prev_time,
													const media_seek_tag* prev_tag);	
												
	void 				LatencyChanged(const media_source& source,
										const media_destination& destination,
										bigtime_t new_latency,
										uint32 flags);

	// BMediaEventLooper methods
	void 				NodeRegistered();
	void 				SetRunMode(run_mode mode);
	void 				HandleEvent(const media_timed_event* event,
									bigtime_t lateness,
									bool realTimeEvent = false);		
									

	void				SetMeter(int32 meter);
	void				SetSpeed(int32 speed);
	
private:
	BBuffer*			FillNextBuffer(bigtime_t eventTime);
	BMediaFile*			fMediaFile[1];
	BMediaTrack*		fTicTrack;
	BMediaTrack*		fTocTrack;
	media_format 		fFormat;
	BBufferGroup* 		fBufferGroup;
	media_output 		fOutput;
	bool				fOutputEnabled;
	bigtime_t			fLatency;
	bigtime_t			fInternalLatency;
	status_t 			fErr;
	
	int32				fSpeed;
	int32				fMeter;
};

#endif
