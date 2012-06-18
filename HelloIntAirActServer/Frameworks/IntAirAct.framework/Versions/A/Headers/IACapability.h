/** Representation of a device capability. */
@interface IACapability : NSObject

/** The description of the capability.
 
 An example could be: "GET /images".
 */
@property (nonatomic, strong) NSString * capability;

@end
