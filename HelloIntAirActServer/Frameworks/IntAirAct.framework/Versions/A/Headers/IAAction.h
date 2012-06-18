/** Representation of a remote procedure call. */
@interface IAAction : NSObject

/** Name of the action to call. */
@property (nonatomic, strong) NSString * action;

/** The parameters of the remote procedure call. */
@property (nonatomic, strong) NSArray * parameters;

@end
