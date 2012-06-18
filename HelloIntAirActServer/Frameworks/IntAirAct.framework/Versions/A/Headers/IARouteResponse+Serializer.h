#import <RoutingHTTPServer/RoutingHTTPServer.h>

@class IAIntAirAct;

/** An extension of RouteResponse to be able to just respond with objects. */
@interface RouteResponse (Serializer)

/** Respond with an object and have it automatically serialized.
 
 @param data The object to serialize.
 @param intAirAct An IAIntAirAct instance.
 */
-(void)respondWith:(id)data withIntAirAct:(IAIntAirAct *)intAirAct;

@end
