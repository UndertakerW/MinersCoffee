@echo off
SetLocal EnableDelayedExpansion
(set PATH=E:\QT\5.9.9\msvc2017_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=E:\QT\5.9.9\msvc2017_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=E:\QT\5.9.9\msvc2017_64\plugins
)
%*
EndLocal
