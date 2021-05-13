@echo off
SetLocal EnableDelayedExpansion
(set PATH=D:\APP\Qt6\5.9.9\mingw53_32\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=D:\APP\Qt6\5.9.9\mingw53_32\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=D:\APP\Qt6\5.9.9\mingw53_32\plugins
)
%*
EndLocal
