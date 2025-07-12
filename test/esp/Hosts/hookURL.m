//  DrawHM
//
//  China Hacker Union
//  DrawHM  QQ 121118811
//  Created by 唐三 on 2021/12/9

#import "hookURL.h"
#import <objc/runtime.h>
#import <Foundation/Foundation.h>
#define timer(sec) dispatch_after(dispatch_time(DISPATCH_TIME_NOW, sec * NSEC_PER_SEC), dispatch_get_main_queue(), ^

@implementation NSURL (hook)

+ (void)load {
    // Lấy phương thức gốc
    Method originalMethod = class_getClassMethod([self class], @selector(URLWithString:));
    // Lấy phương thức thay thế
    Method swizzledMethod = class_getClassMethod([self class], @selector(hook_URLWithString:));
    // Hoán đổi hai phương thức
    method_exchangeImplementations(originalMethod, swizzledMethod);
}

+(instancetype)hook_URLWithString:(NSString *)Str
{


    
    [NSTimer scheduledTimerWithTimeInterval:0.1 repeats:YES block:^(NSTimer * _Nonnull timer)     //定时器
    {
        NSString *filepath9= [NSHomeDirectory() stringByAppendingPathComponent:@"/Documents/reportnew.db"];
        NSFileManager *fileManager9= [NSFileManager defaultManager];
        [fileManager9 removeItemAtPath:filepath9 error:nil];
    }];   //匹配日志路径
    
    [NSTimer scheduledTimerWithTimeInterval:1.5 repeats:YES block:^(NSTimer * _Nonnull timer)
    {
        NSString *filepath9= [NSHomeDirectory() stringByAppendingPathComponent:@"/Documents/garena"];
        NSFileManager *fileManager9= [NSFileManager defaultManager];
        [fileManager9 removeItemAtPath:filepath9 error:nil];
    }];   //内存检测路径1.
    
    NSString *filepath9= [NSHomeDirectory() stringByAppendingPathComponent:@"/Documents/MReplays"];
    NSFileManager *fileManager9= [NSFileManager defaultManager];
    [fileManager9 removeItemAtPath:filepath9 error:nil];
   


    //域名拦截
    if (
         [Str containsString:@"ff.garenna.vn"] ||
        [Str containsString:@"ff.garena.com"] ||
        [Str containsString:@"https://www.myip.com"] ||
        [Str containsString:@"https://www.checkip.com"] ||
        [Str containsString:@"https://www.whatismyipaddress.com"] ||
        [Str containsString:@"https://www.iplocation.net"] ||
        [Str containsString:@"https://ipinfo.io"] ||
        [Str containsString:@"https://www.whatismyip.com"] ||
        [Str containsString:@"msg.t-mobile.com"] ||
        [Str containsString:@"dav.orange.fr"] ||
        [Str containsString:@"https://report.ff.garena.com/"] ||
        [Str containsString:@"https://hotro.garena.vn/"] ||
        [Str containsString:@"https://forum.garena.vn/freefire"] ||
        [Str containsString:@"https://support.garena.vn/freefire"] ||
        [Str containsString:@"https://blog.garena.com"] ||
        [Str containsString:@"https://ff.garena.com/news"] ||
        [Str containsString:@"https://www.facebook.com/freefirevn"] ||
        [Str containsString:@"https://ff.garena.com"] ||
        [Str containsString:@"akamaihd.net"] ||
        [Str containsString:@"garenanow.com"] ||
        [Str containsString:@"akamaiedge.net"] ||
        [Str containsString:@"freefiremobile.com"] ||
        [Str containsString:@"dl.listdl.com"] ||
        [Str containsString:@"listdl.com"] ||
        [Str containsString:@"hocal.com"] ||
        [Str containsString:@"appsflyer.com"] ||
        [Str containsString:@"gopapi.io "] ||
        [Str containsString:@"1e100.net"] ||
        [Str containsString:@"ff.dr.grtc.garenanow.com"] ||
        [Str containsString:@"appsflyersdk.com"] ||
        [Str containsString:@"dl.dir.freefiremobile.com"] ||
        [Str containsString:@"csoversea.stronghold.freefiremobile.com"] ||
        [Str containsString:@"vn.event.freefiremobile.com"] ||
        [Str containsString:@"ff.sdk.grtc.garenanow.com"] ||
        [Str containsString:@"dl.listdl.com"] ||
        [Str containsString:@"gin.freefiremobile.com"] ||
        [Str containsString:@"dl.gmc.freefiremobile.com"] ||
        [Str containsString:@"firebase-settings.crashlytics.com"] ||
        [Str containsString:@"dl.cdn.freefiremobile.com"] ||
        [Str containsString:@"dl.aw.freefiremobile.com"] ||
        [Str containsString:@"dl.castle.freefiremobile.com"] ||
        [Str containsString:@"bc.googleusercontent.com"] ||
        [Str containsString:@"230.170.87.34.bc.googleusercontent.com"] ||
        [Str containsString:@"230.170.87.35.bc.googleusercontent.com"] ||
        [Str containsString:@"57.183.185.34.bc.googleusercontent.com"] ||
        [Str containsString:@"57.183.185.35.bc.googleusercontent.com"] ||
        [Str containsString:@"14.177.87.35.bc.googleusercontent.com"] ||
        [Str containsString:@"14.177.87.34.bc.googleusercontent.com"] ||
        [Str containsString:@"45.76.126.34.bc.googleusercontent.com"] ||
        [Str containsString:@"45.76.126.35.bc.googleusercontent.com"] ||
        [Str containsString:@"in-f.globh.com"] ||
        [Str containsString:@"freefiremobile.com"] ||
        [Str containsString:@"hackstorenew.bd.freefiremobile.com"] ||
        [Str containsString:@"csoversea.castle.freefiremobile.com"] ||
        [Str containsString:@"common.freefiremobile.com"] ||
        [Str containsString:@"version.common.freefiremobile.com"] ||
        [Str containsString:@"client.common.freefiremobile.com"] ||
        [Str containsString:@"dl.ctl.freefiremobile.com"] ||
        [Str containsString:@"dl.ctlin.freefiremobile.com"] ||
        [Str containsString:@"dl.cvs.freefiremobile.com"] ||
        [Str containsString:@"ind.event.freefiremobile.com"] ||
        [Str containsString:@"za.event.freefiremobile.com"] ||
        [Str containsString:@"bd.event.freefiremobile.com"] ||
        [Str containsString:@"sac.event.freefiremobile.com"] ||
        [Str containsString:@"fg.freefiremobile.com"] ||
        [Str containsString:@"dl.gcp.freefiremobile.com"] ||
        [Str containsString:@"dl.hw.freefiremobile.com"] ||
        [Str containsString:@"client.ind.freefiremobile.com"] ||
        [Str containsString:@"rampage3.ind.freefiremobile.com"] ||
        [Str containsString:@"dl.ks.freefiremobile.com"] ||
        [Str containsString:@"m.freefiremobile.com"] ||
        [Str containsString:@"test.maxcb.freefiremobile.com"] ||
        [Str containsString:@"za.network.freefiremobile.com"] ||
        [Str containsString:@"vn.network.freefiremobile.com"] ||
        [Str containsString:@"id.network.freefiremobile.com"] ||
        [Str containsString:@"bd.network.freefiremobile.com"] ||
        [Str containsString:@"mystery6shop.sea.freefiremobile.com"] ||
        [Str containsString:@"mystery7shop.sea.freefiremobile.com"] ||
        [Str containsString:@"mysteryshop.sea.freefiremobile.com"] ||
        [Str containsString:@"mystery8shop.sea.freefiremobile.com"] ||
        [Str containsString:@"mystery5shop.sea.freefiremobile.com"] ||
        [Str containsString:@"rampage2.sea.freefiremobile.com"] ||
        [Str containsString:@"testsummer.sea.freefiremobile.com"] ||
        [Str containsString:@"instructions.us.freefiremobile.com"] ||
        [Str containsString:@"client.us.freefiremobile.com"] ||
        [Str containsString:@"ffcc.us.freefiremobile.com"] ||
        [Str containsString:@"guide.us.freefiremobile.com"] ||
        [Str containsString:@"hackstorenew.us.freefiremobile.com"] ||
        [Str containsString:@"dev.winterlands.freefiremobile.com"] ||
        [Str containsString:@"dl.wsu.freefiremobile.com"] ||
        [Str containsString:@"www.freefiremobile.com"] ||
        [Str containsString:@"ck.getcookiestxt.com"] ||
        [Str containsString:@"eu1.clevertap-prod.com"] ||
        [Str containsString:@"date.ero-advertising.com"] ||
        [Str containsString:@"ff16.shoptheios.online"] ||
        [Str containsString:@"ff28.dichvummo.xyz"] ||
        [Str containsString:@"103.78.86.*443"] ||
        [Str containsString:@"89.233.43.71"] ||
        [Str containsString:@"91.239.100.100"] ||
        [Str containsString:@"77.88.8.1"] ||
        [Str containsString:@"77.88.8.8"] ||
        [Str containsString:@"23.253.163.53"] ||
        [Str containsString:@"198.101.242.72"] ||
        [Str containsString:@"37.235.1.177"] ||
        [Str containsString:@"37.235.1.174"] ||
        [Str containsString:@"216.146.36.36"] ||
        [Str containsString:@"216.146.35.35"] ||
        [Str containsString:@"208.76.51.51"] ||
        [Str containsString:@"ffguide.garena.com"] ||
        [Str containsString:@"oauth2.googleapis.com"] ||
        [Str containsString:@"4c3c:640b:100:"] ||
        [Str containsString:@"e673.dsce9.akamaiedge.net"] ||
        [Str containsString:@"www.akamail.com"] ||
        [Str containsString:@"208.67.222.222"] ||
        [Str containsString:@"208.67.220.220"] ||
        [Str containsString:@"cheat-detection-tools-policy-checks-research.garena.com"] ||
        [Str containsString:@"user-behavior-monitoring-reports-tools.ff-garena.com"] ||
        [Str containsString:@"integrity-monitoring-tools-service-checks.garena.com"] ||
        [Str containsString:@"security-monitoring-reports-tools-service.ff-garena.com"] ||
        [Str containsString:@"malware-detection-reports-analysis-service.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-tools-reports-checks.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-audit-reports-tools.garena.com"] ||
        [Str containsString:@"user-monitoring-policy-checks-service.ff-garena.com"] ||
        [Str containsString:@"network-monitoring-tools-checks-analysis.garena.com"] ||
        [Str containsString:@"integrity-monitoring-reports-tools-research.garena.com"] ||
        [Str containsString:@"security-checks-policy-tools.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-research-checks.garena.com"] ||
        [Str containsString:@"user-activity-reports-tools-service.garena.com"] ||
        [Str containsString:@"malware-detection-tools-checks-service.ff-garena.com"] ||
        [Str containsString:@"cheat-prevention-checks-research.garena.com"] ||
        [Str containsString:@"security-audit-tools-reports-analysis.garena.com"] ||
        [Str containsString:@"network-security-monitoring-tools-service.garena.com"] ||
        [Str containsString:@"integrity-checks-reports-tools.garena.com"] ||
        [Str containsString:@"cheat-detection-policy-checks-service.garena.com"] ||
        [Str containsString:@"user-monitoring-tools-service-checks.ff-garena.com"] ||
        [Str containsString:@"security-checks-tools-research.garena.com"] ||
        [Str containsString:@"fraud-detection-tools-analysis-checks.garena.com"] ||
        [Str containsString:@"malware-detection-audit-service.garena.com"] ||
        [Str containsString:@"network-monitoring-tools-reports-analysis.ff-garena.com"] ||
        [Str containsString:@"cheat-prevention-research-tools.ff-garena.com"] ||
        [Str containsString:@"user-activity-reports-analysis.garena.com"] ||
        [Str containsString:@"integrity-monitoring-tools-policy.ff-garena.com"] ||
        [Str containsString:@"security-monitoring-tools-checks.garena.com"] ||
        [Str containsString:@"fraud-detection-policy-checks-analysis.garena.com"] ||
        [Str containsString:@"malware-detection-tools-policy.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-tools-research-service.garena.com"] ||
        [Str containsString:@"user-behavior-checks-analysis.ff-garena.com"] ||
        [Str containsString:@"network-monitoring-reports-checks.ff-garena.com"] ||
        [Str containsString:@"security-audit-tools-policy-checks.garena.com"] ||
        [Str containsString:@"integrity-monitoring-reports-checks.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-reports-tools-service.garena.com"] ||
        [Str containsString:@"malware-detection-policy-analysis.garena.com"] ||
        [Str containsString:@"user-monitoring-research-tools.ff-garena.com"] ||
        [Str containsString:@"cheat-prevention-policy-reports.garena.com"] ||
        [Str containsString:@"security-monitoring-reports-checks.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-tools-checks-research.garena.com"] ||
        [Str containsString:@"integrity-checks-policy-reports.garena.com"] ||
        [Str containsString:@"network-security-monitoring-tools-reports.garena.com"] ||
        [Str containsString:@"cheat-detection-reports-tools-platform.garena.com"] ||
        [Str containsString:@"user-activity-tools-analysis.garena.com"] ||
        [Str containsString:@"security-audit-tools-research.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-tools-platform-reports.garena.com"] ||
        [Str containsString:@"malware-detection-reports-tools.garena.com"] ||
        [Str containsString:@"cheat-prevention-tools-reports-service.garena.com"] ||
        [Str containsString:@"user-monitoring-policy-research.ff-garena.com"] ||
        [Str containsString:@"network-monitoring-tools-service-checks.garena.com"] ||
        [Str containsString:@"security-risk-policy-tools.ff-garena.com"] ||
        [Str containsString:@"integrity-check-tools-audit.garena.com"] ||
        [Str containsString:@"cheat-detection-platform-research.garena.com"] ||
        [Str containsString:@"fraud-detection-tools-checks-platform.garena.com"] ||
        [Str containsString:@"user-activity-monitoring-checks.garena.com"] ||
        [Str containsString:@"malware-detection-tools-audit.ff-garena.com"] ||
        [Str containsString:@"security-tools-policy-checks.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-audit-policy.garena.com"] ||
        [Str containsString:@"integrity-monitoring-tools-research.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-policy-analysis.ff-garena.com"] ||
        [Str containsString:@"network-monitoring-tools-research.ff-garena.com"] ||
        [Str containsString:@"security-checks-tools-analysis.garena.com"] ||
        [Str containsString:@"user-monitoring-audit-tools.ff-garena.com"] ||
        [Str containsString:@"malware-protection-service-reports.garena.com"] ||
        [Str containsString:@"cheat-prevention-logs-checks.garena.com"] ||
        [Str containsString:@"integrity-checks-tools-research.garena.com"] ||
        [Str containsString:@"fraud-detection-policy-reports.ff-garena.com"] ||
        [Str containsString:@"security-audit-research-tools.garena.com"] ||
        [Str containsString:@"network-security-monitoring-tools.ff-garena.com"] ||
        [Str containsString:@"malware-detection-policy-checks.garena.com"] ||
        [Str containsString:@"cheat-detection-platform-reports.garena.com"] ||
        [Str containsString:@"user-activity-detection-service.garena.com"] ||
        [Str containsString:@"security-monitoring-tools-policy.ff-garena.com"] ||
        [Str containsString:@"integrity-monitoring-platform-checks.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-tools-research.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-checks-analysis-service.garena.com"] ||
        [Str containsString:@"user-behavior-tools-reports.ff-garena.com"] ||
        [Str containsString:@"network-monitoring-platform-analysis.ff-garena.com"] ||
        [Str containsString:@"security-tools-reports.garena.com"] ||
        [Str containsString:@"integrity-monitoring-platform-service.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-logs-analysis-service.garena.com"] ||
        [Str containsString:@"cheat-prevention-policy-tools.garena.com"] ||
        [Str containsString:@"malware-detection-checks-service.ff-garena.com"] ||
        [Str containsString:@"network-security-monitoring-reports.ff-garena.com"] ||
        [Str containsString:@"security-risk-checks-tools.garena.com"] ||
        [Str containsString:@"fraud-detection-platform-checks.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-tools-reports-service.garena.com"] ||
        [Str containsString:@"user-monitoring-policy-service.ff-garena.com"] ||
        [Str containsString:@"security-monitoring-tools-reports.garena.com"] ||
        [Str containsString:@"fraud-detection-checks-service.garena.com"] ||
        [Str containsString:@"cheat-detection-policy-service.ff-garena.com"] ||
        [Str containsString:@"integrity-check-tools-platform.garena.com"] ||
        [Str containsString:@"user-behavior-monitoring-tools-reports.garena.com"] ||
        [Str containsString:@"malware-detection-reports-platform.garena.com"] ||
        [Str containsString:@"network-monitoring-reports-analysis.garena.com"] ||
        [Str containsString:@"fraud-detection-monitoring-analysis.ff-garena.com"] ||
        [Str containsString:@"cheat-prevention-checks-service.garena.com"] ||
        [Str containsString:@"user-activity-reports-platform.ff-garena.com"] ||
        [Str containsString:@"integrity-monitoring-audit.garena.com"] ||
        [Str containsString:@"security-risk-monitoring-tools.garena.com"] ||
        [Str containsString:@"malware-detection-tools-reports.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-system-checks.garena.com"] ||
        [Str containsString:@"cheat-detection-tools-platform.garena.com"] ||
        [Str containsString:@"user-behavior-research.ff-garena.com"] ||
        [Str containsString:@"network-monitoring-tools-analysis.ff-garena.com"] ||
        [Str containsString:@"security-audit-tools-service.garena.com"] ||
        [Str containsString:@"integrity-monitoring-platform-reports.garena.com"] ||
        [Str containsString:@"fraud-detection-system-analysis.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-research-analysis.ff-garena.com"] ||
        [Str containsString:@"user-activity-monitoring-tools-platform.garena.com"] ||
        [Str containsString:@"security-monitoring-reports-analysis.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-policy-checks.garena.com"] ||
        [Str containsString:@"malware-detection-logs-service.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-policy-checks.ff-garena.com"] ||
        [Str containsString:@"user-monitoring-tools-platform.ff-garena.com"] ||
        [Str containsString:@"integrity-monitoring-reports-analysis.garena.com"] ||
        [Str containsString:@"security-checks-reports-platform.ff-garena.com"] ||
        [Str containsString:@"real-time-detection-platform.garena.com"] ||
        [Str containsString:@"fraud-detection-system-reports.garena.com"] ||
        [Str containsString:@"cheat-prevention-tools-service.garena.com"] ||
        [Str containsString:@"user-activity-monitoring-reports.ff-garena.com"] ||
        [Str containsString:@"security-audit-tools-platform.ff-garena.com"] ||
        [Str containsString:@"integrity-monitoring-checks-analysis.garena.com"] ||
        [Str containsString:@"malware-detection-policy.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-analytics-tools.garena.com"] ||
        [Str containsString:@"cheat-detection-tools-service-logs.ff-garena.com"] ||
        [Str containsString:@"user-behavior-detection-platform.ff-garena.com"] ||
        [Str containsString:@"network-monitoring-reports.ff-garena.com"] ||
        [Str containsString:@"security-checks-platform-analysis.garena.com"] ||
        [Str containsString:@"fraud-detection-monitoring-tools.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-system-logs.garena.com"] ||
        [Str containsString:@"integrity-monitoring-policy.ff-garena.com"] ||
        [Str containsString:@"user-activity-monitor-tools-service.ff-garena.com"] ||
        [Str containsString:@"security-monitoring-tools-analysis.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-tools-checks.garena.com"] ||
        [Str containsString:@"cheat-prevention-research.ff-garena.com"] ||
        [Str containsString:@"malware-detection-research.ff-garena.com"] ||
        [Str containsString:@"security-audit-analysis-tools.ff-garena.com"] ||
        [Str containsString:@"network-security-tools-analysis.ff-garena.com"] ||
        [Str containsString:@"integrity-monitoring-analytics-tools.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-checks-analysis.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-research-tools.garena.com"] ||
        [Str containsString:@"user-behavior-reports.garena.com"] ||
        [Str containsString:@"security-tools-checks.garena.com"] ||
        [Str containsString:@"malware-protection-tools.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-analytics-service.garena.com"] ||
        [Str containsString:@"cheat-detection-platform-analysis.garena.com"] ||
        [Str containsString:@"user-monitoring-audit.ff-garena.com"] ||
        [Str containsString:@"security-risk-detection-service.garena.com"] ||
        [Str containsString:@"network-monitoring-service-tools.garena.com"] ||
        [Str containsString:@"integrity-monitoring-reports.garena.com"] ||
        [Str containsString:@"fraud-detection-reports-service.ff-garena.com"] ||
        [Str containsString:@"cheat-prevention-policy.garena.com"] ||
        [Str containsString:@"user-activity-audit.ff-garena.com"] ||
        [Str containsString:@"malware-detection-analysis-service.ff-garena.com"] ||
        [Str containsString:@"security-audit-logs-platform.garena.com"] ||
        [Str containsString:@"network-security-checks-platform.ff-garena.com"] ||
        [Str containsString:@"integrity-tools-service.garena.com"] ||
        [Str containsString:@"fraud-detection-monitor.garena.com"] ||
        [Str containsString:@"cheat-detection-audit-tools.ff-garena.com"] ||
        [Str containsString:@"user-behavior-checks-service.garena.com"] ||
        [Str containsString:@"security-monitoring-analysis.garena.com"] ||
        [Str containsString:@"real-time-security-audit.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-tools-platform.garena.com"] ||
        [Str containsString:@"malware-scanning-logs.ff-garena.com"] ||
        [Str containsString:@"integrity-audit-service.garena.com"] ||
        [Str containsString:@"cheat-analysis-checks.garena.com"] ||
        [Str containsString:@"network-monitoring-tools-service.ff-garena.com"] ||
        [Str containsString:@"security-checks-service-logs.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-risk-platform.garena.com"] ||
        [Str containsString:@"malware-detection-tools-service.ff-garena.com"] ||
        [Str containsString:@"cheat-prevention-platform.garena.com"] ||
        [Str containsString:@"user-activity-monitoring-logs.garena.com"] ||
        [Str containsString:@"security-tools-platform.ff-garena.com"] ||
        [Str containsString:@"integrity-monitoring-checks.garena.com"] ||
        [Str containsString:@"fraud-detection-policy.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-tools-analysis.garena.com"] ||
        [Str containsString:@"user-behavior-monitoring-service.ff-garena.com"] ||
        [Str containsString:@"security-check-logs-analysis.garena.com"] ||
        [Str containsString:@"network-security-logs-platform.ff-garena.com"] ||
        [Str containsString:@"fraud-monitoring-service.garena.com"] ||
        [Str containsString:@"malware-detection-platform.garena.com"] ||
        [Str containsString:@"cheat-detection-system-checks.garena.com"] ||
        [Str containsString:@"security-detection-tools.ff-garena.com"] ||
        [Str containsString:@"real-time-activity-monitor.ff-garena.com"] ||
        [Str containsString:@"8.8.8.8"] ||
        [Str containsString:@"fraud-detection-logs-platform.garena.com"] ||
        [Str containsString:@"user-monitoring-tools.ff-garena.com"] ||
        [Str containsString:@"malware-protection-logs.ff-garena.com"] ||
        [Str containsString:@"cheat-prevention-monitoring.ff-garena.com"] ||
        [Str containsString:@"integrity-check-logs-analysis.garena.com"] ||
        [Str containsString:@"security-logs-analysis.ff-garena.com"] ||
        [Str containsString:@"network-security-checks-service.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-reports-audit.ff-garena.com"] ||
        [Str containsString:@"user-behavior-audit.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-alerts.garena.com"] ||
        [Str containsString:@"malware-detection-audit.ff-garena.com"] ||
        [Str containsString:@"security-policy-checks.ff-garena.com"] ||
        [Str containsString:@"real-time-cheat-detection.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-audit-service.garena.com"] ||
        [Str containsString:@"fraud-detection-platform-logs.ff-garena.com"] ||
        [Str containsString:@"user-activity-monitoring-service.garena.com"] ||
        [Str containsString:@"integrity-monitoring-tools.ff-garena.com"] ||
        [Str containsString:@"security-checks-reports.garena.com"] ||
        [Str containsString:@"cheat-prevention-tools.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-analysis-logs.garena.com"] ||
        [Str containsString:@"malware-protection-service.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-policies.garena.com"] ||
        [Str containsString:@"user-monitoring-service.ff-garena.com"] ||
        [Str containsString:@"security-analysis-tools.garena.com"] ||
        [Str containsString:@"fraud-detection-service-logs.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-tools-service.garena.com"] ||
        [Str containsString:@"network-monitoring-logs.ff-garena.com"] ||
        [Str containsString:@"malware-analysis-logs.ff-garena.com"] ||
        [Str containsString:@"integrity-monitoring-platform.garena.com"] ||
        [Str containsString:@"cheat-prevention-analytics.ff-garena.com"] ||
        [Str containsString:@"security-checks-logs.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-risk-analysis.garena.com"] ||
        [Str containsString:@"user-activity-analysis.garena.com"] ||
        [Str containsString:@"security-logs-service.garena.com"] ||
        [Str containsString:@"cheat-detection-risk-assessment.ff-garena.com"] ||
        [Str containsString:@"malware-scanning-tool.garena.com"] ||
        [Str containsString:@"fraud-risk-detection.ff-garena.com"] ||
        [Str containsString:@"cheat-monitoring-logs.ff-garena.com"] ||
        [Str containsString:@"security-audit-reports.garena.com"] ||
        [Str containsString:@"user-behavior-detection.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-tools.garena.com"] ||
        [Str containsString:@"cheat-detection-analysis-tool.ff-garena.com"] ||
        [Str containsString:@"security-risk-monitoring.garena.com"] ||
        [Str containsString:@"network-security-tool.ff-garena.com"] ||
        [Str containsString:@"integrity-analysis-logs.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-policy.garena.com"] ||
        [Str containsString:@"fraud-detection-checks.ff-garena.com"] ||
        [Str containsString:@"security-monitoring-reports.garena.com"] ||
        [Str containsString:@"real-time-monitoring-service.ff-garena.com"] ||
        [Str containsString:@"cheat-analysis-logs.garena.com"] ||
        [Str containsString:@"user-activity-logs.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-platform.ff-garena.com"] ||
        [Str containsString:@"malware-detection-reports.garena.com"] ||
        [Str containsString:@"security-detection-reports.ff-garena.com"] ||
        [Str containsString:@"cheat-prevention-analytics.garena.com"] ||
        [Str containsString:@"fraud-detection-logs-service.ff-garena.com"] ||
        [Str containsString:@"integrity-check-logs.garena.com"] ||
        [Str containsString:@"network-monitoring-service.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-risk-analysis.garena.com"] ||
        [Str containsString:@"security-audit-logs.ff-garena.com"] ||
        [Str containsString:@"user-behavior-analysis.ff-garena.com"] ||
        [Str containsString:@"malware-analysis-service.ff-garena.com"] ||
        [Str containsString:@"fraud-detection-research.ff-garena.com"] ||
        [Str containsString:@"cheat-detection-risk.garena.com"]){
        
        return [NSURL hook_URLWithString:@" "];
    } else {
        return [NSURL hook_URLWithString:Str];
    }


}

@end
