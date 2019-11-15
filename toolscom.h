#ifndef __TOOLS_COMMON_H__
#define __TOOLS_COMMON_H__

#include <list>
#include <string>
#include <time.h>
#include "sys/timeb.h"
#include "sys/stat.h"
#include "istddef.h"

/**
 * @brief G系列运行环境相关目录类型
 * @note  用于读取目录时指定目录类型
 */
enum en_MCGS_DIR
{
    MCGS_DIR_WORK,          //应用程序工作目录，对应环境变量键为MCGS_WORK_DIR
    MCGS_DIR_CFG,           //应用程序配置文件目录，对应环境变量键为MCGS_CFG_DIR
    MCGS_DIR_STORAGE,       //应用程序存储文件目录，对应环境变量键为MCGS_STORAGE_DIR
    MCGS_DIR_PROJECT,       //应用程序的工程数据文件目录，对应环境变量键为MCGS_PROJECT_DIR
    MCGS_DIR_POINTERCAL,    //升级校准文件目录，对应环境变量键为MCGS_POINTERCAL_DIR，windows及虚拟机模拟器不支持
    MCGS_DIR_SYSCONFIG,     //升级分辨率文件目录，对应环境变量键为MCGS_SYSCONFIG_DIR，windows及虚拟机模拟器不支持
    MCGS_DIR_EXPORT,        //导出数据时默认目录，对应环境变量键为MCGS_EXPORT_DIR
    MCGS_DIR_FONTS,         //运行环境字体文件目录，对应环境变量键值为MCGS_FONTS_DIR，windows及虚拟机模拟器不支持
};


/**
 * @brief 获取系统启动后的时钟数
 * @return 系统启动后的时钟数
 */
_APIDECL(long long) Mcgs_GetTickCount();


/**
 * @brief 操作蜂鸣器发出响声
 * @param dwFreq 蜂鸣器声音频率，
 * @param dwDuration 蜂鸣器发出声音的时长
 * @return 无
 * @注意事项
 * 1对于Arm来说dwFreq值无效
 * 2liunx系统下需要使用命令（sudo apt-get install beep）安装beep且需要注意声卡驱动(sudo modprobe pcspkr)
 * 3此函数会卡死线程尽量不要长时间执行
 */
_APIDECL(void) Mcgs_Beep(unsigned int dwFreq, unsigned int dwDuration);


/**
 * @brief 将时间转换为指定格式的字符串
 * @param t 需要转换的时间
 * @param strFormat 需要转换的格式
 * @return 成功返回指定格式字符串，错误返回空字符串
 */
//_APIDECL(CString) McgsFormatTime(CTime& t, CString strFormat);


/**
 * @brief 获取带毫秒值的系统时间
 * @param tS 获取的时间秒
 * @param lMs 获取的毫秒数
 */
_APIDECL(void) Mcgs_GetTime(time_t& tS, long& lMs);


/**
 * @brief 创建指定目录，如果不存在才创建，可多级目录创建
 * @param strDirectory:指定需要创建的目录路径(比如C:/aaa/ddd)
 * @return 成功返回true，失败返回false
 * @注意事项 目录分隔符请使用'/'
 */
_APIDECL(bool) Mcgs_CreateDirectory(const char* strDirectory);


/**
 * @brief 创建指定目录及目录下的文件与子目录，可删除多级目录，非递归实现
 * @param strDirectory:指定需要删除的目录路径
 * @return 成功返回0，若中间存在文件或文件删除失败返回-1,删除不会被终止
 * @注意事项 目录分隔符请使用'/'
 */
_APIDECL(int) Mcgs_DeleteDirectory(const char* strDirectory);


/**
 * @brief 获取指定类型的数据文件的目录
 * @param enDirType:需要获取的目录类型
 * @return 成功返回非空字符串，失败返回空字符串
 * @note windows模拟环境相关目录与a33目录结构差距较大，使用时需要注意
 */
_APIDECL(const char*) Mcgs_GetDirectory(en_MCGS_DIR enDirType);


/**
 * @brief 删除指定类型的数据,该接口无需调用DataBackup_Init(),可直接使用,调用接口请确保运行环境退出
 * @param delDataType:1表示删除配方数据，2表示删除历史数据，4表示删除报警数据，8表示初值数据，可同时操作，如：3表示删除配方数据与历史数据，15表示删除所有数据
 * @param save_base_dir:指定路径下的存盘数据，若为空，默认表示tpc环境的存储目录，非空，表示指定删除的存储目录
 * @return 为0表示成功，1表示配方数据删除存在失败，2表示历史数据删除存在失败，4表示报警数据删除存在失败，可同时表示操作错误
 * @注意事项 某个文件或文件夹删除失败会继续删除其他数据文件，不会终止删除
 */
_APIDECL(int) Mcgs_DelSaveData(int delDataType, const char* save_base_dir = NULL);


/**
 * @brief   check whether the path is mounted
 */
_APIDECL(bool) Mcgs_Check_Mount_Path(const char* path);


//打开文件,用法同open,只能打开U盘挂载的分区文件
// -1表示失败，成功返回文件描述符,
/**
 * @brief Mcgs_udisk_open:创建U盘路径下的文件,只针对嵌入式U盘创建文件,用法以及参数同c open,其他情况请不要使用
 * @param pathname:文件名, 可输入/mnt/usb1/开头的绝对路径,或相对路径, 缺省/mnt/usb1/,如:mydir/test.txt同/mnt/usb1/mydir/test.txt,必须保证mydir目录存在
 * @param flags:同open函数的flag,如O_CREAT|O_TRUNC等
 * @param mode:权限,同open函数,默认为0755
 * @return -1表示失败，成功返回文件描述符
 */
_APIDECL(int) Mcgs_udisk_open(const char *pathname, int flags, mode_t mode = 0755);


//创建路径,可输入/mnt/usb1/开头的绝对路径,或相对路径, 缺省/mnt/usb1/
//成功放回0,失败返回-1
/**
 * @brief Mcgs_udisk_mkpath:创建U盘路径,只针对嵌入式U盘创建路径,用法以及参数同c mkdir,其他情况请不要使用
 * @param pathname:路径名,可输入/mnt/usb1/开头的绝对路径,或相对路径, 缺省/mnt/usb1/,如:mydir/同/mnt/usb1/mydir,可多级创建
 * @param mode:权限,同mkdir函数,默认为0755
 * @return:成功放回0,失败返回-1
 */
_APIDECL(int) Mcgs_udisk_mkpath(const char* pathname, mode_t mode = 0755);


/**
 * @brief Mcgs_udisk_rename:重命名到U盘路径,只针对嵌入式U盘重命名,用法以及参数同c rename,其他情况请不要使用
 * @param oldpath:源文件名,可输入任意全路径,或相对与工作路径的相对路径
 * @param newpath:目的文件名,可输入/mnt/usb1/开头的绝对路径,或相对路径, 缺省/mnt/usb1/,如:mydir/同/mnt/usb1/mydir,必须保证父级目录存在
 * @return:成功放回0,失败返回-1
 */
_APIDECL(int) Mcgs_udisk_rename(const char* oldpath, const char* newpath);


/**
 * @brief Mcgs_IsEqual: 判断两个浮点数是否相等;可进行float和double的比较
 * @param fValue_a:浮点数a
 * @param fValue_b:浮点数b
 * @return:成功返回true,失败返回false
 */
_APIDECL(bool) Mcgs_IsEqual(___in long double fValue_a, ___in long double fValue_b, ___in const long double esp _DEFAULT(1e-6));

/**
 * @brief Mcgs_Sleep: 执行计时功能
 * @param nSleepTime:需要计时的时长，单位ms
 * @return 正常计时结束时返回0，异常情况返回-1
 * @note 系统正常中断不会结束计时
 */
_APIDECL(int) Mcgs_Sleep(___in long long  llSleepTime);

#endif // __TOOLS_COMMON_H__
