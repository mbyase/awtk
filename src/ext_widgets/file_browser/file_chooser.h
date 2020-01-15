﻿/**
 * File:   file_chooser.h
 * Author: AWTK Develop Team
 * Brief:  file/folder choosers
 *
 * Copyright (c) 2020 - 2020 Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2020-01-12 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_FILE_CHOOSER_H
#define TK_FILE_CHOOSER_H

#include "base/widget.h"

BEGIN_C_DECLS

struct _file_chooser_t;
typedef struct _file_chooser_t file_chooser_t;

/**
 * @class file_chooser_t
 * @annotation ["scriptable"]
 * 文件/目录选择器
 */
typedef struct _file_chooser_t {
  /**
   * @property {char*} init_dir
   * 初始目录。
   */
  char* init_dir;

  /**
   * @property {char*} filter
   * 过滤规则。
   */
  char* filter;

  /**
   * @property {tk_on_done_t} on_done 
   * 接受结果的回调函数。
   */
  tk_on_done_t on_done;

  /**
   * @property {void*} on_done_ctx
   * 用户数据。
   */
  void* on_done_ctx;

  /*result*/
  /**
   * @property {str_t} cwd 
   * 当前路径。
   */
  str_t cwd;

  /**
   * @property {str_t} filename; 
   * 当前选择的文件。
   */
  str_t filename;

  /**
   * @property {bool_t} aborted
   * 是否取消了选择。
   */
  bool_t aborted;

  /*private*/
  const char* ui;
} file_chooser_t;

/**
 * @method file_chooser_create
 * @annotation ["constructor", "scriptable"]
 * @param {const char*} init_dir 初始目录
 * @param {const char*} filter 过滤规则(如".jpg.png.gif")。
 * 创建file_chooser对象
 *
 * @return {file_chooser_t*} 对象。
 */
file_chooser_t* file_chooser_create(const char* init_dir, const char* filter);

/**
 * @method file_chooser_cast
 * 转换为file_chooser对象(供脚本语言使用)。
 *
 * @annotation ["cast", "scriptable"]
 * @param {void*} data file_chooser对象。
 *
 * @return {file_chooser_t*} 对象。
 */
file_chooser_t* file_chooser_cast(void* data);

/**
 * @method file_chooser_set_on_done
 * @param {file_chooser_t*} chooser file_chooser对象。
 * @param {tk_on_done_t*} on_done 接受选择结果的回调函数。
 * @param {void*} on_done_ctx 接受选择结果的回调函数的上下文。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t file_chooser_set_on_done(file_chooser_t* chooser, tk_on_done_t on_done,
                                 void* on_done_ctx);

/**
 * @method file_chooser_choose_file_for_save
 * 为了保存而选择文件。
 *
 * @annotation ["scriptable"]
 * @param {file_chooser_t*} chooser file_chooser对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t file_chooser_choose_file_for_save(file_chooser_t* chooser);

/**
 * @method file_chooser_choose_file_for_open
 * 为了打开而选择文件。
 *
 * @annotation ["scriptable"]
 * @param {file_chooser_t*} chooser file_chooser对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t file_chooser_choose_file_for_open(file_chooser_t* chooser);

/**
 * @method file_chooser_choose_folder
 * 选择目录。
 *
 * @annotation ["scriptable"]
 * @param {file_chooser_t*} chooser file_chooser对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t file_chooser_choose_folder(file_chooser_t* chooser);

/**
 * @method file_chooser_get_dir
 * 获取目录。
 *
 * @annotation ["scriptable"]
 * @param {file_chooser_t*} chooser file_chooser对象。
 *
 * @return {const char*} 返回选择的目录。
 */
const char* file_chooser_get_dir(file_chooser_t* chooser);

/**
 * @method file_chooser_get_filename
 * 获取文件名。
 *
 * @annotation ["scriptable"]
 * @param {file_chooser_t*} chooser file_chooser对象。
 *
 * @return {const char*} 返回选择的文件名。
 */
const char* file_chooser_get_filename(file_chooser_t* chooser);

/**
 * @method file_chooser_is_aborted
 * 用户是否取消了选择。
 *
 * @annotation ["scriptable"]
 * @param {file_chooser_t*} chooser file_chooser对象。
 *
 * @return {bool_t} 返回用户是否取消了选择。
 */
bool_t file_chooser_is_aborted(file_chooser_t* chooser);

/**
 * @method file_chooser_destroy
 * 销毁file_chooser对象(选择完成后自动调用)。
 *
 * @param {file_chooser_t*} chooser file_chooser对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t file_chooser_destroy(file_chooser_t* chooser);

/*UI 资源文件名*/
#define FILE_CHOOSER_UI_CHOOSE_FOLDER "folder_chooser"
#define FILE_CHOOSER_UI_CHOOSE_FILE_FOR_OPEN "file_chooser_for_open"
#define FILE_CHOOSER_UI_CHOOSE_FILE_FOR_SAVE "file_chooser_for_save"

/*控件名*/
#define FILE_CHOOSER_OK "ok"
#define FILE_CHOOSER_CANCEL "cancel"

END_C_DECLS

#endif /*TK_FILE_CHOOSER_H*/
