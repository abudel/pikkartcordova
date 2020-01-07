/* ===============================================================================
 * Pikkart S.r.l. CONFIDENTIAL
 * -------------------------------------------------------------------------------
 * Copyright (c) 2014-2018 Pikkart S.r.l. All Rights Reserved.
 * Pikkart is a trademark of Pikkart S.r.l., registered in Europe,
 * the United States and other countries.
 *
 * NOTICE:  All information contained herein is, and remains the property of
 * Pikkart S.r.l. and its suppliers, if any. The intellectual and technical
 * concepts contained herein are proprietary to Pikkart S.r.l. and its suppliers
 * and may be covered by E.U., U.S. and Foreign Patents, patents in process,
 * and are protected by trade secret or copyright law. Dissemination of this
 * information or reproduction of this material is strictly forbidden unless
 * prior written permission is obtained from Pikkart S.r.l..
 * ===============================================================================*/
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

extern NSString * PKTARNativeInterfaceInterestPointFoundNotification;
extern NSString * PKTARNativeInterfaceInterestPointLostNotification;
/**
 * \class PKTARNativeInterface
 * \brief The Pikkart Augmented Reality Native Interface
 *
 * The  Pikkart Augmented Reality  Native Interface
 * It is singleton class providing methods that build an objective c interface
 * on c++ recognition core
 *
 */
@interface PKTARNativeInterface : NSObject

#pragma mark - init
/*! \brief get PKTARNativeInterface object
 *
 *  \return get PKTARNativeInterface object
 *
 */
+(instancetype) sharedInstance;

/*! \brief get a 4x4 float identity matrix
 *
 *  \param matrix a float **, inizialized with a 4x4 identity matrix
 *
 *  \warning
 *  matrix should be deallocated from caller.
 */
+(void)Identity4x4:(float**)matrix;

/*! \brief set a 4x4 float identity matrix
 *
 *  \param matrix a float[16] vector previously allocated, inizialized as identity matrix
 *
 */
+(void)setIdentity4x4:(float *)matrix;

/*! \brief copy 4x4 float matrix from in to out parameter
 *
 *  \param in a float[16] vector previously allocated
 *  \param out a float[16] vector previously allocated
 *
 */
+(void)copy4x4:(float *)in andOut:(float *)out;

/*! \brief initialize a PKTARNativeInterface object
 *
 */
-(void)initialize;

/*! \brief init a PKTARNativeInterface object recognition parameters
 *
 *  \param app_data_dir directory full path to app root directory
 *  \param cameraSize size of photocamera rendering, in iOS is fixed to 640x480
 *  \param diagonal extension in inch of device screen diagonal
 */
-(bool)InitRecognitionWithAppDataDir:(char *)app_data_dir
                       andCameraSize:(CGSize)cameraSize
                         andDiagonal:(float)diagonal;

/*! \brief init a PKTARNativeInterface object projection matrix
 *
 *  \param hfov horizontal focal lens size
 *  \param vfov vertical focal lens size
 */
-(void)InitProjectionMatrixWithHFov:(float) hfov
                            andVFov:(float) vfov;

/*! \brief init a PKTARNativeInterface object projection matrix
 *
 *  \param fx horizontal focal lens x
 *  \param fy vertical focal lens y
 *  \param cx horizontal focal lens x
 *  \param cy vertical focal lens y
 */
-(void)InitProjectionMatrixWithFx:(float)fx
                            andFy:(float)fy
                            andCx:(float)cx
                            andCy:(float)cy;


/*! \brief set a PKTARNativeInterface object projection matrix
 *
 *  \param hfov horizontal focal lens size
 *  \param vfov vertical focal lens size
 */
-(void)SetProjectionMatrixWithHFov:(float) hfov
                           andVFov:(float) vfov;

/*! \brief set a PKTARNativeInterface object projection matrix
 *
 *  \param fx horizontal focal lens x
 *  \param fy vertical focal lens y
 *  \param cx horizontal focal lens x
 *  \param cy vertical focal lens y
 */
-(void)SetProjectionMatrix2WithFx:(float)fx
                            andFy:(float)fy
                            andCx:(float)cx
                            andCy:(float)cy;

#pragma mark - Camera Rendering
/*! \brief update view port
 *
 *  \param size CGSize Current Device Screen Size
 *  \param angle photocamera angle orientation
 */
-(void)UpdateViewportWithSize:(CGSize)size
                     andAngle:(int)angle;

/*! \brief force photocamera Init
 *
 *  \param size CGSize Current Device Screen Size
 *  \param angle photocamera angle orientation
 */
-(void) ForceInitCameraGL:(CGSize)cameraSize;

/*! \brief Render photocamera frame inside a openGL texture
 *
 *  \param viewPortSize CGSize Current Device Screen Size
 *  \param angle photocamera angle orientation
 */
-(void) RenderCameraGLWithViewPortSize:(CGSize)viewPortSize
                            andAngle:(int)angle;

/*! \brief Analyze current device photocamera frame
 *
 */
-(bool)ImageProcessing;

/*! \brief copy current device photocamera frame inside Pikkart SDK recognition framework
 *
 *  \param frame current device photocamera frame, sampled with
 *         kCVPixelFormatType_420YpCbCr8BiPlanarFullRange format
 */
-(void)CopyNewFrame:(unsigned char *)frame withCameraSize:(CGSize)size;

/*! \brief update Model View Matrix
 *
 */
-(void) UpdateModelViewMatrix;

/*! \brief set camera original sample frame size
 *
 */
-(void)SetCameraOriginalSize:(CGSize)originalSize;

#pragma mark - Recognition

/*! \brief set recognition features as mode, orange dot effect and cloud http request interval
 *
 *  \param storage recognition storage, see PKTRecognitionStorage enum in PKTRecognitionOptions.h
 *  \param enable_effect enable orange detected points animation
 *  \param cloud_request_interval interval between consecutive cloud web request
 */
-(void)SetRecognitionWith:(int)storage
          andEnableEffect:(bool)enable_effect
  andCloudRequestInterval:(int)cloud_request_interval;

/*! \brief Start recognition process
 *
 */
-(void)StartRecognition;

/*! \brief Stop recognition process
 *
 */
-(void)StopRecognition;

/*! \brief save local marker inside Pikkart SDK recognition framework
 *
 *  \param markerId marker unique identifier
 *  \param targetDescriptor marker raw representation
 *  \return true if operation successfull, otherwise false
 */
-(bool)SaveLocalMarkerWithId:(char *) markerId
               andTargetDesc:(char *)targetDescriptor;

/*! \brief delete local marker from Pikkart SDK recognition framework
 *
 *  \param markerId marker unique identifier
 *  \return true if operation successfull, otherwise false
 *
 */
-(bool)DeleteLocalMarkerWithId:(char *)markerId;

/*! \brief Start Orange Effect
 *
 */
-(void) StartEffect;

/*! \brief Stop Orange Effect
 *
 */
-(void) StopEffect;

/*! \brief get Server Buffer
 *
 *  \return local server buffer used to save current device frame image
 */
-(void *) GetServerBuffer;

/*! \brief update Server Buffer
 *
 *  \return update loca server buffer used to save current device frame image
 */
-(unsigned long)UpdateServerBuffer;

/*! \brief force a search marker
 *
 *  \param markerId marker unique identifier
 */
-(void)ForceMarkerSearch:(char *) markerId;

/*! \brief force a search marker with internal id
 *
 *  \param marker_internal_Id marker unique internal identifier
 */
-(void)ForceMarkerSearchInternalId:(int)marker_internal_Id;

/*! \brief get Tracked Markers Internal IDs
 *
 *  \param an array of marker_internal_Id
 */
-(NSArray *)GetTrackedMarkersInternalIDs;

/*! \brief check if we tracking marker name
 *
 *  \param marker_database_Id marker database id
 *
 *  \return true if we tracking marker, false otherwise
 *
 */
-(bool)IsTrackingName:(char *)marker_database_Id;

/*! \brief check if we tracking marker name
 *
 *  \param marker_internal_Id marker internal database id
 *
 *  \return true if we tracking marker, false otherwise
 */
-(bool)IsTrackingInternalID:(int) marker_internal_Id;

/*! \brief get marker Name Width
 *
 *  \param marker_database_Id marker database id
 *
 *  \return retrieve Width associated to marker name
 */
-(float)GetMarkerWidthName:(char *) marker_database_Id;

/*! \brief get marker Name Width
 *
 *  \param marker_internal_Id marker internal id
 *
 *  \return retrieve Width associated to marker name
 */
-(float)GetMarkerWidthInternalID:(int) marker_internal_Id;

/*! \brief get marker Name Height
 *
 *  \param marker_database_Id marker database id
 *
 *  \return retrieve Height associated to marker name
 */
-(float)GetMarkerHeightName:(char *) marker_database_Id;

/*! \brief get marker Name Height
 *
 *  \param marker_internal_Id marker internal id
 *
 *  \return retrieve Height associated to marker name
 */
-(float)GetMarkerHeightInternalID:(int) marker_internal_Id;

/*! \brief get Marker Pose Name
 *
 *  \param marker_database_Id marker database id
 *
 *  \return retrieve 4x4 float matrix marker pose
 */
-(NSArray *)GetMarkerPoseName:(char *) marker_database_Id;

/*! \brief get Marker Pose Internal ID
 *
 *  \param marker_internal_Id marker internal id
 *
 *  \return retrieve 4x4 float matrix marker pose
 */
-(NSArray *)GetMarkerPoseInternalID:(int)marker_internal_Id;

/*! \brief check if recognition Process  has been tracking a marker
 *
 *  \return true if tracking is on, otherwise return false
 */
-(bool)IsTracking;

/*! \brief get current Marker object, if any
 *
 *  \return a generic NSObject
 */
-(id)GetCurrentMarker;

/*! \brief get Marker by Database Id
 *
 *  \param marker_database_id marker database id
 *
 *  \return a generic NSObject
 */
-(id)GetMarkerByDatabaseId:(char *)marker_database_id;

/*! \brief get Global Data Set
 *
 *  \param databaseName a database name, used for multimarkers
 *
 *  \return true if database loading is correct, otherwise false
 */
-(bool)LoadGlobalDataset:(char *)databaseName;

#pragma mark - interface versus c++ recognition library to objc
/*! \brief called from recognition process engine when a local marker is found
 *
 *  \param marker_internal_id marker internal id
 *  \param marker_database_id marker database id
 *
 */
-(void)LocalMarkerFound:(int) marker_internal_id onDatabase:(char *)marker_database_id;

/*! \brief called  from recognition process engine when a local marker is not found
 *
 */
-(void)LocalMarkerNotFound;

/*! \brief called from recognition process engine when, after tracking a marker,
 *         we lost marker tracking
 */
-(void)MarkerTrackingLost:(int) marker_internal_id onDatabase:(char *)marker_database_id;

/*! \brief called from recognition process engine when we try to start a recognition
 *         and engine is not compatible with recognized marker
 */
-(void)MarkerEngineToUpdate:(int) marker_internal_id onDatabase:(char *)marker_database_id;

/*! \brief called from recognition process engine when we found a AR Logo
 *
 *  \param marker_internal_id marker internal id
 *  \param marker_database_id marker database id
 *  \param code AR Logo code
 *
 */
-(void)ARLogoFound:(int)marker_internal_id
           onDatabase:(char *)marker_database_id
             withCode:(int)code;

/*! \brief execute a sync markers
 *
 *
 */
-(void)syncMarkersWithFolder;

/*! \brief call from discover process when a Point of Interest is found
 *
 *  \param ip_id point of interest unique identifier
 *
 */
-(void)InterestPointFound:(int) ip_id;

/*! \brief call from discover process when a Point of Interest is lost
 *
 *  \param ip_id point of interest unique identifier
 *
 */
-(void)InterestPointLost:(int) ip_id;

/*! \brief call from recognition process when a marker is found
 *
 *  \param marker_database_id marker database identifier
 *
 */
-(void)DownloadMarker:(char *)marker_database_id;

#pragma mark - GeoLocation methods
/*! \brief start GeoLocation process
 *
 *  \return true if successful, false otherwise
 */
-(bool)StartGeolocation;

/*! \brief add augmented marker used in geolocalization subsystem
 *
 *  \param Id marker augmented marker identifier
 *  \param lat latitude value
 *  \param longitude longitude value
 *  \param altitude altitude value
 *
 */
-(void)AddAugmentedMarker:(NSString *)Id andLatitude:(double)lat andLongitude:(double)longitude andAltitude:(double)altitude;

/*! \brief delete augmented marker used in geolocalization subsystem
 *
 *  \param Id marker augmented marker identifier
 */
-(void)DeleteAugmentedMarker:(NSString *)Id;

/*! \brief update augmented marker position
 *
 *  \param Id marker augmented marker identifier
 *  \param lat latitude value
 *  \param longitude longitude value
 *  \param altitude altitude value
 *
 *  \return return current distance from augmented marker to current user position
 */
-(double)UpdateUserPosition:(NSString *)Id andLatitude:(double)lat andLongitude:(double)longitude andAltitude:(double)altitude;

/*! \brief update user orientation
 *
 *  \param Id marker augmented marker identifier
 
 *
 *  \return return current position of augmented marker as tupla of 3 values {x,y,z}
 */
-(NSArray *)UpdateUserOrientation:(NSString *)Id;

/*! \brief update camera projection matrix
 *
 *  \param cameraWidth current camera width
 *  \param cameraHeight current camera height
 *  \param viewPortWidth current view port width
 *  \param viewportHeight current view port height
 *  \param angle current view port angle
 *
 *  \warning not called on iOS device
 */
-(void)UpdateProjectionCameraWithWidth:(int)cameraWidth
                            andHeight:(int)cameraHeight
                     andViewPortWidth:(int)viewPortWidth
                    andViewPortHeight:(int)viewportHeight
                              andAngle:(int)angle;

/*! \brief set accelerometor raw data to x,y,z
 *
 *  \param x x-position derived from core motion
 *  \param y y-position derived from core motion
 *  \param z z-position derived from core motion
 *
 *  \warning not called on iOS device
 */
-(void) SetAccelerometerWithX:(float)x andY:(float)y andZ:(float)z;

/*! \brief set north magnetic raw data to x,y,z
 *
 *  \param x x-position derived from core motion
 *  \param y y-position derived from core motion
 *  \param z z-position derived from core motion
 *
 *  \warning not called on iOS device
 */
-(void) SetMagneticWithX:(float)x andY:(float)y andZ:(float)z;

/*! \brief set gyroscope raw data to x,y,z
 *
 *  \param x x-position derived from core motion
 *  \param y y-position derived from core motion
 *  \param z z-position derived from core motion
 *
 *  \warning not called on iOS device
 */
-(void) SetGyroWithX:(float)x andY:(float)y andZ:(float)z;

/*! \brief Compute device orientation
 *
 *  \param event_timestamp event timestamp
 *
 *  \warning not called on iOS device
 */
-(void) ComputeOrientation:(long) event_timestamp;

/*! \brief check if device is face down
 *
 *  \param event_timestamp event timestamp
 *
 *  \return true if device is face down, false otherwise
 *
 *  \warning not called on iOS device
 */
-(bool) IsLookingDown;

/*! \brief set Orientation Matrix
 *
 *  \param matrix orientation matrix
 *
 *  \warning not called on iOS device
 */
-(void)SetOrientationMatrix:(double *)matrix;

#pragma mark - Discover
/*! \brief Load discover model
 *
 *  Load discover model found inside markers3D.bundle custom bundle
 *
 *  \param modelname name of discover model
 */
-(bool)loadDiscoverModel:(NSString *)modelName;

/*! \brief Get position of interest point
 *
 *  \param ip_id name interest point uniqe identifier
 *  \param pos current interest point position as float[2] with float[0] = x-screenPosition and
 *         float[0] = y-screenPosition
 */
-(void)getPositionOfInterestPoint:(int)ip_id andPosition:(float *)pos;


/*! \brief Get PublicID of interest point
 *
 *  \param ip_id name interest point uniqe identifier
 *  \return a string with PublicID
 */
-(NSString *)getInterestPointPublicID:(int)ip_id;

#pragma mark - Deep Learning
/*! \brief Prepare Image for deep learning recognition mode
 *
 *  \param src_data raw bytes of photocamera device camera
 *  \param src_width photocamera device camera width
 *  \param src_height photocamera device camera height
 *  \param orientation photocamera device camera orientation
 *  \param is_yuv tell if raw bytes are in yuv format
 *  \param output raw bytes prepare for tensor flow deep recognition process
 *  \param dst_width output destination raw width
 *  \param dst_height output destination raw height
 *  \param toRGB tell if output data shuold be rgb-format
 *  \param toFloat tell if output data shuold be as float granularity
 *  \param mean mean used for deep learning image frame process
 *  \param std standar deviation used for deep learning image frame process
 */
-(void) PrepareImageForDeep:(unsigned char *)src_data withSrcWidth:(int)src_width andSrcHeight:(int)src_height
            withOrientation:(int)orientation withYuv:(bool)is_yuv andCrop:(bool)crop andPercentage:(float)percentage andOutputImage:(unsigned char *)output withDstWidth:(int)dst_width withDstHeight:(int)dst_height isToRGB:(bool)toRGB
                  isToFloat:(bool)toFloat withMean:(float)mean withStd:(float)std;

#pragma mark - crypto methods
+(NSString *)CreateSignatureWith:(NSString *) method
                         andBody:(NSString *) body
                         andDate:(NSString *) date
                         andPath:(NSString *) path;
+(bool)CheckLicense;
+(void)reset;

#pragma mark - Calibration methods
-(void)calibrate:(int)square_size;
-(void)calibrateAddImage;
-(void)calibrateResetImage;

-(void)DecryptCalibParams:(void *)data withOutputParams:(float *)outParams;

// camera calibration callbacks
-(void)CameraCalibratorSuccess:(double)fx andFy:(double)fy andCx:(double)cx andCy:(double)cy andAvgError:(double)avgError andMinX:(double)minx andMinY:(double)miny andMinZ:(double)minz andMaxX:(double)maxx andMaxY:(double)maxy andMaxZ:(double)maxz;
-(void)CameraCalibratorFailed:(NSError *)error;

#pragma mark - property callbacks
@property (nonatomic) id recognitionManager;
@property(nonatomic,readonly) int cameraWidth;
@property(nonatomic,readonly) int cameraHeight;
@property (nonatomic,readonly) CGSize cameraSize;
@property(nonatomic,readonly) float * projectionMatrix;
@property(nonatomic) float * modelViewMatrix;

#ifdef __URHO3D__
#pragma mark - methods for urhosharp rendering
-(void)GetYDataToRender:(unsigned char **)ydata;
-(void)GetUVDataToRender:(unsigned char **)uvdata;
#endif

@end
