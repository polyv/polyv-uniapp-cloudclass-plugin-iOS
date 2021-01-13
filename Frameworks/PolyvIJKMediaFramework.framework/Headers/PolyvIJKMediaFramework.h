/*
 * IJKMediaFramework.h
 *
 * Copyright (c) 2013 Bilibili
 * Copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#import <UIKit/UIKit.h>

//! Project version number for IJKMediaFramework.
FOUNDATION_EXPORT double PolyvIJKMediaFrameworkVersionNumber;

//! Project version string for IJKMediaFramework.
FOUNDATION_EXPORT const unsigned char PolyvIJKMediaFrameworkVersionString[];

#import <PolyvIJKMediaFramework/PLVIJKMediaPlayback.h>
#import <PolyvIJKMediaFramework/PLVIJKMPMoviePlayerController.h>
#import <PolyvIJKMediaFramework/PLVIJKFFOptions.h>
#import <PolyvIJKMediaFramework/PLVIJKFFMoviePlayerController.h>
#import <PolyvIJKMediaFramework/PLVIJKAVMoviePlayerController.h>
#import <PolyvIJKMediaFramework/PLVIJKMediaModule.h>
#import <PolyvIJKMediaFramework/PLVIJKMediaPlayer.h>
#import <PolyvIJKMediaFramework/PLVIJKNotificationManager.h>
#import <PolyvIJKMediaFramework/PLVIJKKVOController.h>
#import <PolyvIJKMediaFramework/PLVIJKSDLGLViewProtocol.h>

// backward compatible for old names
#define IJKMediaPlaybackIsPreparedToPlayDidChangeNotification IJKMPMediaPlaybackIsPreparedToPlayDidChangeNotification
#define IJKMoviePlayerLoadStateDidChangeNotification IJKMPMoviePlayerLoadStateDidChangeNotification
#define IJKMoviePlayerPlaybackDidFinishNotification IJKMPMoviePlayerPlaybackDidFinishNotification
#define IJKMoviePlayerPlaybackDidFinishReasonUserInfoKey IJKMPMoviePlayerPlaybackDidFinishReasonUserInfoKey
#define IJKMoviePlayerPlaybackStateDidChangeNotification IJKMPMoviePlayerPlaybackStateDidChangeNotification
#define IJKMoviePlayerIsAirPlayVideoActiveDidChangeNotification IJKMPMoviePlayerIsAirPlayVideoActiveDidChangeNotification
#define IJKMoviePlayerVideoDecoderOpenNotification IJKMPMoviePlayerVideoDecoderOpenNotification
#define IJKMoviePlayerFirstVideoFrameRenderedNotification IJKMPMoviePlayerFirstVideoFrameRenderedNotification
#define IJKMoviePlayerFirstAudioFrameRenderedNotification IJKMPMoviePlayerFirstAudioFrameRenderedNotification
#define IJKMoviePlayerFirstAudioFrameDecodedNotification IJKMPMoviePlayerFirstAudioFrameDecodedNotification
#define IJKMoviePlayerFirstVideoFrameDecodedNotification IJKMPMoviePlayerFirstVideoFrameDecodedNotification
#define IJKMoviePlayerOpenInputNotification IJKMPMoviePlayerOpenInputNotification
#define IJKMoviePlayerFindStreamInfoNotification IJKMPMoviePlayerFindStreamInfoNotification
#define IJKMoviePlayerComponentOpenNotification IJKMPMoviePlayerComponentOpenNotification

#define IJKMPMoviePlayerAccurateSeekCompleteNotification IJKMPMoviePlayerAccurateSeekCompleteNotification
#define IJKMoviePlayerSeekAudioStartNotification IJKMPMoviePlayerSeekAudioStartNotification
#define IJKMoviePlayerSeekVideoStartNotification IJKMPMoviePlayerSeekVideoStartNotification
