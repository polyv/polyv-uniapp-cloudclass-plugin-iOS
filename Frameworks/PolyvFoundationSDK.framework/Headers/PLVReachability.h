#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>

//! Project version number for MacOSReachability.
FOUNDATION_EXPORT double PLVReachabilityVersionNumber;

//! Project version string for MacOSReachability.
FOUNDATION_EXPORT const unsigned char PLVReachabilityVersionString[];

#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

extern NSString *const kPLVReachabilityChangedNotification;

typedef NS_ENUM(NSInteger, PLVNetworkStatus) {
    // Apple NetworkStatus Compatible Names.
    PLVNotReachable = 0,
    PLVReachableViaWiFi = 2,
    PLVReachableViaWWAN = 1
};

@class PLVReachability;

typedef void (^PLVNetworkReachable)(PLVReachability * reachability);
typedef void (^PLVNetworkUnreachable)(PLVReachability * reachability);
typedef void (^PLVNetworkReachability)(PLVReachability * reachability, SCNetworkConnectionFlags flags);


@interface PLVReachability : NSObject

@property (nonatomic, copy) PLVNetworkReachable    reachableBlock;
@property (nonatomic, copy) PLVNetworkUnreachable  unreachableBlock;
@property (nonatomic, copy) PLVNetworkReachability reachabilityBlock;

@property (nonatomic, assign) BOOL reachableOnWWAN;


+(instancetype)reachabilityWithHostname:(NSString*)hostname;
// This is identical to the function above, but is here to maintain
//compatibility with Apples original code. (see .m)
+(instancetype)reachabilityWithHostName:(NSString*)hostname;
+(instancetype)reachabilityForInternetConnection;
+(instancetype)reachabilityWithAddress:(void *)hostAddress;
+(instancetype)reachabilityForLocalWiFi;
+(instancetype)reachabilityWithURL:(NSURL*)url;

-(instancetype)initWithReachabilityRef:(SCNetworkReachabilityRef)ref;

-(BOOL)startNotifier;
-(void)stopNotifier;

-(BOOL)isReachable;
-(BOOL)isReachableViaWWAN;
-(BOOL)isReachableViaWiFi;

// WWAN may be available, but not active until a connection has been established.
// WiFi may require a connection for VPN on Demand.
-(BOOL)isConnectionRequired; // Identical DDG variant.
-(BOOL)connectionRequired; // Apple's routine.
// Dynamic, on demand connection?
-(BOOL)isConnectionOnDemand;
// Is user intervention required?
-(BOOL)isInterventionRequired;

-(PLVNetworkStatus)currentReachabilityStatus;
-(SCNetworkReachabilityFlags)reachabilityFlags;
-(NSString*)currentReachabilityString;
-(NSString*)currentReachabilityFlags;

@end
