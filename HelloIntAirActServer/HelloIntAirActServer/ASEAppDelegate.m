#import "ASEAppDelegate.h"

#import <IntAirAct/IntAirAct.h>

#import "ASEResponse.h"

@interface ASEAppDelegate ()

@property (nonatomic, strong) IAIntAirAct * intAirAct;

@end

@implementation ASEAppDelegate

@synthesize window;

@synthesize intAirAct;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    intAirAct = [IAIntAirAct new];
    
    intAirAct.client = NO;
    
    // Normally there's no need to run our server on any specific port.
	// Technologies like Bonjour allow clients to dynamically discover the server's port at runtime.
	// However, for easy testing you may want force a certain port so you can just hit the refresh button.
    intAirAct.port = 12345;
    
    [intAirAct addMappingForClass:[ASEResponse class] withKeypath:@"responses" withAttributes:@"message", nil];
    
    ASEResponse * res = [ASEResponse new];
    res.message = @"hello world";
    
    [intAirAct.httpServer get:@"/hello" withBlock:^(RouteRequest * request, RouteResponse * response) {   
        [response respondWith:res withIntAirAct:self.intAirAct];
    }];
    
    NSError * error = nil;
	if(![intAirAct start:&error])
	{
		NSLog(@"Error starting HTTP Server: %@", error);
	}
}

@end
