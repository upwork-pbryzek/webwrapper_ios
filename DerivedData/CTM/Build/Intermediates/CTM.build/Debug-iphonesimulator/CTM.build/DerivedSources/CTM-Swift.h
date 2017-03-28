// Generated by Apple Swift version 3.0.2 (swiftlang-800.0.63 clang-800.0.42.1)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if defined(__has_attribute) && __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
@import ObjectiveC;
@import Foundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class UIWindow;
@class UIApplication;

SWIFT_CLASS("_TtC3CTM11AppDelegate")
@interface AppDelegate : UIResponder <UIApplicationDelegate>
@property (nonatomic, strong) UIWindow * _Nullable window;
- (BOOL)application:(UIApplication * _Nonnull)application didFinishLaunchingWithOptions:(NSDictionary<UIApplicationLaunchOptionsKey, id> * _Nullable)launchOptions;
- (void)applicationWillResignActive:(UIApplication * _Nonnull)application;
- (void)applicationDidEnterBackground:(UIApplication * _Nonnull)application;
- (void)applicationWillEnterForeground:(UIApplication * _Nonnull)application;
- (void)applicationDidBecomeActive:(UIApplication * _Nonnull)application;
- (void)applicationWillTerminate:(UIApplication * _Nonnull)application;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class UIWebView;
@class NSBundle;
@class NSCoder;

SWIFT_CLASS("_TtC3CTM19FirstViewController")
@interface FirstViewController : UIViewController <UIAlertViewDelegate, UIWebViewDelegate>
@property (nonatomic, copy) NSString * _Nonnull lastUserId;
@property (nonatomic, weak) IBOutlet UIWebView * _Null_unspecified webview;
- (IBAction)editClick:(id _Nonnull)sender;
- (void)viewDidLoad;
- (void)loadWebviewByUserId;
- (void)viewDidAppear:(BOOL)animated;
- (void)initWebview SWIFT_METHOD_FAMILY(none);
- (void)loadHelpWebview;
- (void)loadClinicalWebview;
- (void)loadWebviewUrlWithUrlString:(NSString * _Nonnull)urlString;
- (void)showUrlErrorDialog;
- (void)launchUserIdPopup;
- (void)loadHelpUrl;
- (void)completeLoadActionWithUrlString:(NSString * _Nonnull)urlString completion:(void (^ _Nonnull)(NSInteger))completion;
- (void)didReceiveMemoryWarning;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class NSURLSession;
@class NSError;

SWIFT_CLASS("_TtC3CTM4HTTP")
@interface HTTP : NSObject <NSURLSessionDelegate>
@property (nonatomic, strong) NSURLSession * _Null_unspecified session;
@property (nonatomic, strong) NSError * _Nonnull invalidURLError;
@property (nonatomic, strong) NSError * _Nonnull syncResultAccessError;
- (NSString * _Nonnull)query:(NSDictionary<NSString *, id> * _Nonnull)parameters;
- (NSString * _Nonnull)percentEncodeString:(id _Nonnull)originalObject;
- (void)addCookies:(NSURL * _Nonnull)URL newCookies:(NSDictionary<NSString *, NSString *> * _Nonnull)newCookies;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

@class NSURLSessionTask;
@class NSURLAuthenticationChallenge;
@class NSURLCredential;
@class NSHTTPURLResponse;
@class NSURLSessionDataTask;

@interface HTTP (SWIFT_EXTENSION(CTM)) <NSURLSessionTaskDelegate, NSURLSessionDataDelegate>
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didReceiveChallenge:(NSURLAuthenticationChallenge * _Nonnull)challenge completionHandler:(void (^ _Nonnull)(enum NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task willPerformHTTPRedirection:(NSHTTPURLResponse * _Nonnull)response newRequest:(NSURLRequest * _Nonnull)request completionHandler:(void (^ _Nonnull)(NSURLRequest * _Nullable))completionHandler;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
- (void)URLSession:(NSURLSession * _Nonnull)session dataTask:(NSURLSessionDataTask * _Nonnull)dataTask didReceiveData:(NSData * _Nonnull)data;
- (void)URLSession:(NSURLSession * _Nonnull)session task:(NSURLSessionTask * _Nonnull)task didCompleteWithError:(NSError * _Nullable)error;
@end

@class NSURLResponse;
@class NSHTTPCookie;

/**
  The only reason this is not a struct is the requirements for
  lazy evaluation of \code
  headers
  \endcode and \code
  cookies
  \endcode, which is mutating the
  struct. This would make those properties unusable with \code
  HTTPResult
  \endcodes
  declared with \code
  let
  \endcode
*/
SWIFT_CLASS("_TtC3CTM10HTTPResult")
@interface HTTPResult : NSObject
@property (nonatomic, copy) NSData * _Nullable content;
@property (nonatomic, strong) NSURLResponse * _Nullable response;
@property (nonatomic) NSError * _Nullable error;
@property (nonatomic, readonly, copy) NSURLRequest * _Nullable request;
@property (nonatomic, strong) NSURLSessionTask * _Nullable task;
@property (nonatomic) NSJSONReadingOptions JSONReadingOptions;
@property (nonatomic, readonly, copy) NSString * _Nonnull reason;
@property (nonatomic, readonly) BOOL isRedirect;
@property (nonatomic, readonly) BOOL isPermanentRedirect;
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
- (nonnull instancetype)initWithData:(NSData * _Nullable)data response:(NSURLResponse * _Nullable)response error:(NSError * _Nullable)error task:(NSURLSessionTask * _Nullable)task OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly) id _Nullable json;
@property (nonatomic, readonly, copy) NSString * _Nullable text;
@property (nonatomic, copy) NSDictionary<NSString *, NSHTTPCookie *> * _Nonnull cookies;
@property (nonatomic, readonly) BOOL ok;
@property (nonatomic, readonly, copy) NSURL * _Nullable url;
@property (nonatomic, copy) NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> * _Nonnull links;
- (void)cancel;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC3CTM20SecondViewController")
@interface SecondViewController : UIViewController
- (void)viewDidLoad;
- (void)didReceiveMemoryWarning;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


@interface NSURLResponse (SWIFT_EXTENSION(CTM))
@property (nonatomic, readonly, copy) NSDictionary<NSString *, NSString *> * _Nonnull HTTPHeaders;
@end

@class UITextField;
@class UITableView;
@class UITableViewCell;
@class UIView;
@class UIButton;
@class UILabel;

SWIFT_CLASS("_TtC3CTM11UserIdPopup")
@interface UserIdPopup : UIViewController <UIScrollViewDelegate, UITableViewDelegate, UITableViewDataSource>
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly) NSInteger TEXTFIELD_USERID;)
+ (NSInteger)TEXTFIELD_USERID;
@property (nonatomic, weak) IBOutlet UIView * _Null_unspecified popupView;
@property (nonatomic, weak) IBOutlet UITextField * _Null_unspecified userIdTxt;
@property (nonatomic, weak) IBOutlet UIButton * _Null_unspecified cancelBtn;
@property (nonatomic, weak) IBOutlet UIButton * _Null_unspecified okBtn;
@property (nonatomic, weak) IBOutlet UIButton * _Null_unspecified helpBtn;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified titleLbl;
@property (nonatomic, weak) IBOutlet UIView * _Null_unspecified div;
@property (nonatomic, weak) IBOutlet UITableView * _Null_unspecified searchTable;
- (IBAction)cancelClick:(id _Nonnull)sender;
- (IBAction)helpClick:(id _Nonnull)sender;
- (IBAction)okClick:(id _Nonnull)textField;
- (void)textFieldDidChange:(UITextField * _Nonnull)textField;
- (void)showSearchErrorDialogWithErr:(NSString * _Nonnull)err;
- (void)doSearchAPIWithSearchTerm:(NSString * _Nonnull)searchTerm;
- (void)reloadSearchTable;
- (void)viewWillAppear:(BOOL)animated;
- (void)initUserIdText SWIFT_METHOD_FAMILY(none);
- (void)setBkgdColor;
/**
  ///
*/
- (NSInteger)tableView:(UITableView * _Nonnull)tableView numberOfRowsInSection:(NSInteger)section;
- (UITableViewCell * _Nonnull)tableView:(UITableView * _Nonnull)tableView cellForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (NSInteger)numberOfSectionsInTableView:(UITableView * _Nonnull)tableView;
- (void)tableView:(UITableView * _Nonnull)tableView didSelectRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (void)tableView:(UITableView * _Nonnull)tableView willDisplayCell:(UITableViewCell * _Nonnull)cell forRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

#pragma clang diagnostic pop