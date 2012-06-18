#import "ASEHelloRoutingServer.h"

#import <RoutingHTTPServer/RoutingHTTPServer.h>

#import "ASEHTTPConnection.h"

@interface ASEHelloRoutingServer ()

@property (nonatomic, strong) RoutingHTTPServer * httpServer;

@end

@implementation ASEHelloRoutingServer

@synthesize httpServer;

- (id)init
{
    self = [super init];
    if (self) {
        // Initalize our http server
        httpServer = [[RoutingHTTPServer alloc] init];
        
        [httpServer setType:@"_http._tcp"];
        
        // Normally there's no need to run our server on any specific port.
        // Technologies like Bonjour allow clients to dynamically discover the server's port at runtime.
        // However, for easy testing you may want force a certain port so you can just hit the refresh button.
        [httpServer setPort:12345];
        
        // We're going to extend the base HTTPConnection class with our MyHTTPConnection class.
        // This allows us to do all kinds of customizations.
        [httpServer setConnectionClass:[ASEHTTPConnection class]];
        
        [httpServer get:@"/hello" withBlock:^(RouteRequest * request, RouteResponse * response) {
            [response setHeader:@"Server" value:@"Hello"];
            [response setHeader:@"Content-Type" value:@"application/json;charset=utf-8"];
            [response respondWithString:@"{\"responses\":{\"message\":\"hello world\"}}"];
        }];
        
        NSError * error = nil;
        if(![httpServer start:&error])
        {
            NSLog(@"Error starting HTTP Server: %@", error);
        }
    }
    return self;
}

-(void)dealloc
{
    [httpServer stop];
    
    httpServer = nil;
}

@end
