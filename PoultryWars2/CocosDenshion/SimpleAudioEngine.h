/*
 *  SimpleAudioEngine.h
 *  SweetDreams
 *
 *  Created by João Caxaria on 5/24/09.
 *  Copyright 2009 Cocos2d-iPhone - If you find this useful, please give something back.
 *  Original by skeeet.
 *  http://groups.google.com/group/cocos2d-iphone-discuss/browse_thread/thread/166c5c488b55a858/98c606d518033637?lnk=gst&q=AVAudioPlayer&pli=1
 */
#import "CocosDenshion.h"
#import "CDAudioManager.h"

/**
 A wrapper to the CDAudioManager object.
 This is recommended for basic audio requirements. If you just want to play some sound fx
 and some background music and have no interest in learning the lower level workings then
 this is the interface to use.
 
 Requirements:
 - Firmware: OS 2.2 or greater 
 - Files: SimpleAudioEngine.*, CocosDenshion.*
 - Frameworks: OpenAL, AudioToolbox, AVFoundation
 @since v0.8
 */
@interface SimpleAudioEngine : NSObject {
	
	BOOL	muted_;
	
}

/** whether or not the engine is muted */
@property (readwrite) BOOL muted;
/** Background music volume. Range is 0.0f to 1.0f */
@property (readwrite) float backgroundMusicVolume;
/** Effects volume. Range is 0.0f to 1.0f */
@property (readwrite) float effectsVolume;

/** returns the shared instance of the SimpleAudioEngine object */
+ (SimpleAudioEngine*) sharedEngine;

/** plays background music in a loop*/
-(void) playBackgroundMusic:(NSString*) filePath;
/** plays background music, if loop is true the music will repeat otherwise it will be played once */
-(void) playBackgroundMusic:(NSString*) filePath loop:(BOOL) loop;
/** stops playing background music */
-(void) stopBackgroundMusic;
/** pauses the background music */
-(void) pauseBackgroundMusic;
/** rewind the background music */
-(void) rewindBackgroundMusic;
/** returns whether or not the background music is playing */
-(BOOL) isBackgroundMusicPlaying;

/** plays an audio effect randomly from the three file paths ----added by Manan Patel*/
-(ALuint) playRandomEffect:(NSString*)filePath1 filepath2:(NSString*)filePath2 filePath3:(NSString*)filePath3;

/** plays an audio effect with a file path*/
-(ALuint) playEffect:(NSString*) filePath;

/** plays an audio effect with a file path, pitch, pan and gain */
-(ALuint) playEffect:(NSString*) filePath pitch:(Float32) pitch pan:(Float32) pan gain:(Float32) gain;
/** preloads an audio effect */
-(void) preloadEffect:(NSString*) filePath;
/** unloads an audio effect from memory */
-(void) unloadEffect:(NSString*) filePath;

@end
