#import <Foundation/Foundation.h>

@protocol AgoraAudioFrameDelegate <NSObject>
@required

- (BOOL)onRecordAudioFrame:(AgoraAudioFrame* _Nonnull)frame;
- (BOOL)onPlaybackAudioFrame:(AgoraAudioFrame* _Nonnull)frame;
- (BOOL)onMixedAudioFrame:(AgoraAudioFrame* _Nonnull)frame;
- (BOOL)onPlaybackAudioFrameBeforeMixing:(AgoraAudioFrame* _Nonnull)frame uid:(NSUInteger)uid;
@end