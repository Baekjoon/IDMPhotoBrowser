//
//  IDMPhoto.h
//  IDMPhotoBrowser
//
//  Created by Michael Waterfall on 17/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDMPhotoProtocol.h"
#import "AFNetworking.h"
#import <AssetsLibrary/AssetsLibrary.h>

// This class models a photo/image and it's caption
// If you want to handle photos, caching, decompression
// yourself then you can simply ensure your custom data model
// conforms to IDMPhotoProtocol
@interface IDMPhoto : NSObject <IDMPhoto>

// Progress download block, used to update the circularView
typedef void (^IDMProgressUpdateBlock)(CGFloat progress);

// Properties
@property (nonatomic, strong) NSString *caption;
@property (nonatomic, strong) NSURL *photoURL;
@property (nonatomic, strong) IDMProgressUpdateBlock progressUpdateBlock;
@property (nonatomic, strong) ALAsset *photoAsset;

// Class
+ (IDMPhoto *)photoWithImage:(UIImage *)image;
+ (IDMPhoto *)photoWithFilePath:(NSString *)path;
+ (IDMPhoto *)photoWithURL:(NSURL *)url;
+ (IDMPhoto *)photoWithAsset:(ALAsset *)asset;

+ (NSArray *)photosWithImages:(NSArray *)imagesArray;
+ (NSArray *)photosWithFilePaths:(NSArray *)pathsArray;
+ (NSArray *)photosWithURLs:(NSArray *)urlsArray;
+ (NSArray *)photosWithAssets:(NSArray *)assetsArray;

// Init
- (id)initWithImage:(UIImage *)image;
- (id)initWithFilePath:(NSString *)path;
- (id)initWithURL:(NSURL *)url;
- (id)initWithAsset:(ALAsset *)asset;

@end

