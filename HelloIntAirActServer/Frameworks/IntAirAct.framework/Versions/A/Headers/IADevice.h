/** Representation of a Device found on the network */
@interface IADevice : NSObject

/** The capabilities of the device */
@property (nonatomic, strong) NSSet * capabilities;

/** The host of the device. */
@property (nonatomic, strong) NSString * host;

/** The name of the device. */
@property (nonatomic, strong) NSString * name;

/** The port on which the device is running IntAirAct */
@property (nonatomic) NSInteger port;

@end
