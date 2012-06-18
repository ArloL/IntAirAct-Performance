#import "ASEAppDelegate.h"

#import "ASEHelloRoutingServer.h"

@interface ASEAppDelegate ()

@property (nonatomic, strong) ASEHelloRoutingServer * helloServer;

@end

@implementation ASEAppDelegate

@synthesize window;

@synthesize helloServer;

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    helloServer = [ASEHelloRoutingServer new];
}

-(void)applicationDidBecomeActive:(NSNotification *)notification
{
    if (!helloServer) {
        helloServer = [ASEHelloRoutingServer new];
    }
}

-(void)applicationWillTerminate:(NSNotification *)notification
{
    helloServer = nil;
}

-(BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
    return YES;
}

@end
