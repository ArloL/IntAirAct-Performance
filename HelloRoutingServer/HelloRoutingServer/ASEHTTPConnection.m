#import "ASEHTTPConnection.h"

#import <CocoaHTTPServer/HTTPMessage.h>
#import <RoutingHTTPServer/RoutingHTTPServer.h>

@implementation ASEHTTPConnection

- (void)setHeadersForResponse:(HTTPMessage *)response isError:(BOOL)isError {
	[http.defaultHeaders enumerateKeysAndObjectsUsingBlock:^(id field, id value, BOOL *stop) {
		[response setHeaderField:field value:value];
	}];
    
	if (headers && !isError) {
		[headers enumerateKeysAndObjectsUsingBlock:^(id field, id value, BOOL *stop) {
			[response setHeaderField:field value:value];
		}];
	}
    
	// Set the connection header if not already specified
	NSString *connection = [response headerField:@"Connection"];
	if (!connection) {
		connection = [self shouldDie] ? @"close" : @"keep-alive";
		[response setHeaderField:@"Connection" value:connection];
	}
}


- (NSData *)preprocessResponse:(HTTPMessage *)response {
	[self setHeadersForResponse:response isError:NO];
	
	// Override me to customize the response headers
	// You'll likely want to add your own custom headers, and then return [super preprocessResponse:response]
	
	// Add optional response headers
	if ([httpResponse respondsToSelector:@selector(httpHeaders)])
	{
		NSDictionary *responseHeaders = [httpResponse httpHeaders];
		
		NSEnumerator *keyEnumerator = [responseHeaders keyEnumerator];
		NSString *key;
		
		while ((key = [keyEnumerator nextObject]))
		{
			NSString *value = [responseHeaders objectForKey:key];
			
			[response setHeaderField:key value:value];
		}
	}
	
	return [response messageData];
}

@end
