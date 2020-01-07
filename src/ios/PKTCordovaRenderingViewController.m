//
//  PKTECMGeoLocationViewController.m
//  App Modello
//
//  Created by Roberto Avanzi on 15/06/16.
//  Copyright © 2016 Progetti di Impresa. All rights reserved.
//

#import "PKTCordovaRenderingViewController.h"

@interface PKTCordovaRenderingViewController ()<PKTCPSyncCloudMarkersDelegate>
@property (nonatomic) UIStackView * waitStackView;
@property (nonatomic) UIActivityIndicatorView * waitIndicatorView;
@property (nonatomic) UIProgressView * progressView;
@property (nonatomic) PKTRecognitionOptions * options;
@end

@implementation PKTCordovaRenderingViewController

#pragma mark - PKTCPSyncCloudMarkersDelegate methods
- (void)didFailMarkerDownload:(NSError *)error {
    [self.waitIndicatorView stopAnimating];
    [self.progressView setProgress:0.0 animated:true];
    NSLog(@"Errore durante download markers");
}

- (void)didFinishSyncMarkerWithError:(NSError *)error {
    [self.waitIndicatorView stopAnimating];
    [self.progressView setProgress:0.0 animated:true];
    [self.waitStackView removeFromSuperview];
    [self StartRecognition:self.options andRecognitionCallback:[self valueForKey:@"_renderingListener"]];
}

-(void)progressWithValue:(double)value {
    [self.progressView setProgress:value animated:true];
}

-(void)closeRendering:(UIButton *)button {
    [self dismissViewControllerAnimated:true completion:nil];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    UIButton * backButton=[UIButton buttonWithType:UIButtonTypeCustom];
    backButton.translatesAutoresizingMaskIntoConstraints=false;
    NSString * frameworkBundlePath = [[NSBundle mainBundle] pathForResource:@"pikkartARRenderingCloudPlugin"
                                                                     ofType:@"bundle"];
    NSBundle * frameworkBundle = [NSBundle bundleWithPath:frameworkBundlePath];
    UIImage * backImage=[UIImage imageNamed:@"baseline_backspace_white_36pt.png"
                                   inBundle:frameworkBundle
              compatibleWithTraitCollection:nil];
    [backButton setImage:backImage forState:UIControlStateNormal];
    [backButton setFrame:CGRectMake(0,0, backImage.size.width, backImage.size.height)];
    [backButton addTarget:self action:@selector(closeRendering:) forControlEvents:UIControlEventTouchUpInside];
    backButton.alpha=0.8f;
    [self.view addSubview:backButton];
    [self.view bringSubviewToFront:backButton];
    [backButton.widthAnchor constraintEqualToConstant:backImage.size.width].active=true;
    [backButton.heightAnchor constraintEqualToConstant:backImage.size.height].active=true;
    [backButton.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:20.f].active=true;
    [backButton.topAnchor constraintEqualToAnchor:self.view.topAnchor constant:20.f].active=true;
    
    //Wait Indicator View
    self.waitIndicatorView = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
    self.waitIndicatorView.hidesWhenStopped = true;
    self.waitIndicatorView.translatesAutoresizingMaskIntoConstraints = false;
    self.waitIndicatorView.tintColor = [UIColor systemBlueColor];
    
    //Progress View
    self.progressView = [[UIProgressView alloc] init];
    self.progressView.translatesAutoresizingMaskIntoConstraints = false;
    self.progressView.progressTintColor = [UIColor systemBlueColor];
    self.progressView.progress = 0.0;
    
    //Stack View
    self.waitStackView = [[UIStackView alloc] init];
    self.waitStackView.translatesAutoresizingMaskIntoConstraints = false;
    self.waitStackView.axis = UILayoutConstraintAxisVertical;
    self.waitStackView.distribution = UIStackViewDistributionFillProportionally;
    self.waitStackView.alignment = UIStackViewAlignmentFill;
    self.waitStackView.spacing = 20;

    [self.waitStackView addArrangedSubview:self.waitIndicatorView];
    [self.waitStackView addArrangedSubview:self.progressView];
    [self.view addSubview:self.waitStackView];
    [self.view bringSubviewToFront:self.waitStackView];
    
    [self.waitStackView.centerXAnchor constraintEqualToAnchor:self.view.centerXAnchor].active = true;
    [self.waitStackView.centerYAnchor constraintEqualToAnchor:self.view.centerYAnchor].active = true;
    [self.waitStackView.leadingAnchor constraintEqualToAnchor:self.view.leadingAnchor constant:40.0].active = true;
    [self.waitStackView.trailingAnchor constraintEqualToAnchor:self.view.trailingAnchor constant:-40.0].active = true;
    [self.waitIndicatorView startAnimating];
    PKTCloudRecognitionInfo * cloudInfo = [PKTCloudRecognitionInfo PKTCloudRecognitionInfoWithWebURL:@"https://ws.ar-7.pikkart.com" andDatabaseName:@""];
    self.options = [PKTRecognitionOptions PKTRecognitionOptionsWithRecognitionStorage:PKTLOCAL andMode:PKTRECOGNITION_CONTINUOS_SCAN andCloudAuthInfo:cloudInfo];
    [PKTRenderingControllerCloudPlugIn syncMarkers:true
                                     withCloudInfo:self.options.cloudAuthInfo
                                  withSyncDelegate:self];
}

-(void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    // FIXME
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


-(BOOL)shouldAutorotate
{
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
        return false;
    
    return true;
}


-(UIInterfaceOrientationMask)supportedInterfaceOrientations
{
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
    {
        return UIInterfaceOrientationMaskPortrait;
    }
    return UIInterfaceOrientationMaskLandscape;
}

@end
