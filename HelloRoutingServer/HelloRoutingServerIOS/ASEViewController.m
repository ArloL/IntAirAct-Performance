//
//  ASEViewController.m
//  HelloRoutingServerIOS
//
//  Created by O'Keeffe Arlo Louis on 2012-05-26.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ASEViewController.h"

@interface ASEViewController ()

@end

@implementation ASEViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone) {
        return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
    } else {
        return YES;
    }
}

@end
