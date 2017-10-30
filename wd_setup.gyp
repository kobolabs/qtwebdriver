{
  'includes': [
    'wd.gypi',
    'wd_common.gypi',
  ],

  'target_defaults': {
    'includes': [
      'wd_build_options.gypi',
      'wd_qt_tools.gypi',
    ],

    # TODO: review include_dirs
    'include_dirs': [
      'inc/',
      '<(QT_INC_PATH)',
      '<(INTERMEDIATE_DIR)',
    ],

    'conditions': [
      [ '<(QT5) == 1', {
        'conditions': [
          ['OS=="linux"', {
            'libraries': [
              '-L<(QT_LIB_PATH)',
              '-lQt5Network',
              '-lQt5Widgets',
              '-lQt5Quick',
              '-lQt5Qml',
              '-lQt5Sql',
              '-lQt5Gui',
              '-lQt5Xml',
              '-lQt5OpenGL',
              '-lQt5PrintSupport',
              '-lQt5Core',
              '-lpthread',
              '-lrt',
              '-ldl',
              '-licuuc',
              '-licudata',
              '-licui18n',
              '-lQt5MultimediaWidgets',
              '-lQt5Sensors',
              '-lQt5Multimedia',
            ],
          } ],
          ['OS=="win"', {
            'libraries': [
             '-l<(QT_LIB_PATH)/Qt5Network',
             '-l<(QT_LIB_PATH)/Qt5Gui',
             '-l<(QT_LIB_PATH)/Qt5Core',
             '-l<(QT_LIB_PATH)/Qt5Widgets',
             '-l<(QT_LIB_PATH)/Qt5Qml',
             '-l<(QT_LIB_PATH)/Qt5Quick',
             '-l<(QT_LIB_PATH)/Qt5Xml',
             '-l<(QT_LIB_PATH)/Qt5MultimediaWidgets',
             '-l<(QT_LIB_PATH)/Qt5Multimedia',
             '-luser32.lib',
             '-lws2_32.lib',
             '-lshell32.lib',
             '-ladvapi32.lib',
             '-lpsapi.lib',
             '-lkernel32.lib',
             '-luserenv.lib',
            ],
          } ],
          [ 'OS=="mac"', {
            'link_settings': {
              'libraries': [
                '<(QT_LIB_PATH)/libQt5Network.a',
                '<(QT_LIB_PATH)/libQt5Gui.a',
                '<(QT_LIB_PATH)/libQt5Core.a',
                '<(QT_LIB_PATH)/libQt5Widgets.a',
                '<(QT_LIB_PATH)/libQt5Qml.a',
                '<(QT_LIB_PATH)/libQt5Quick.a',
                '<(QT_LIB_PATH)/libQt5MultimediaWidgets.a',
                '<(QT_LIB_PATH)/libQt5Multimedia.a',
                '<(QT_LIB_PATH)/libQt5Xml.a',
                '$(SDKROOT)/System/Library/Frameworks/Foundation.framework',
                '$(SDKROOT)/System/Library/Frameworks/CoreFoundation.framework',
                '$(SDKROOT)/System/Library/Frameworks/ApplicationServices.framework',
                '$(SDKROOT)/System/Library/Frameworks/Security.framework',
              ],
            },
            'xcode_settings': {
              'FRAMEWORK_SEARCH_PATHS': '<(QT_LIB_PATH)',
            },
          } ],
          ['OS=="android"', {
            'libraries': [
              '-L<(QT_LIB_PATH)',
              '-lQt5Widgets',
              '-lQt5Network',
              '-lQt5Gui',
              '-lQt5Core',
              '-lQt5AndroidExtras',
              '-L<(ANDROID_LIB)',
              '-lgnustl_shared',
              '-llog',
            ],
          } ],
          [ 'OS=="ios"', {
            'link_settings': {
              'libraries': [
                '<(QT_LIB_PATH)/libQt5Network_iphonesimulator.a',
                '<(QT_LIB_PATH)/libQt5Gui_iphonesimulator.a',
                '<(QT_LIB_PATH)/libQt5Core_iphonesimulator.a',
                '<(QT_LIB_PATH)/libQt5Widgets_iphonesimulator.a',
                '<(QT_LIB_PATH)/libQt5MultimediaWidgets_iphonesimulator.a',
                '<(QT_LIB_PATH)/libQt5Multimedia_iphonesimulator.a',
                '<(QT_LIB_PATH)/libQt5Qml_iphonesimulator.a',
                '<(QT_LIB_PATH)/libQt5OpenGL_iphonesimulator.a',
                '<(QT_LIB_PATH)/libQt5Quick_iphonesimulator.a',
                '<(QT_LIB_PATH)/libQt5Xml_iphonesimulator.a',
                '<(QT_LIB_PATH)/libQt5PlatformSupport_iphonesimulator.a',
                '<(QT_LIB_PATH)/../plugins/platforms/libqios_iphonesimulator.a',
                '$(SDKROOT)/System/Library/Frameworks/Foundation.framework',
                '$(SDKROOT)/System/Library/Frameworks/CoreFoundation.framework',
                '$(SDKROOT)/System/Library/Frameworks/CoreGraphics.framework',
                '$(SDKROOT)/System/Library/Frameworks/CoreText.framework',
                '$(SDKROOT)/System/Library/Frameworks/OpenGLES.framework',
                '$(SDKROOT)/System/Library/Frameworks/QuartzCore.framework',
                '$(SDKROOT)/System/Library/Frameworks/UIKit.framework',
                'libz.dylib',
              ],
            },

            'xcode_settings': {
              'TARGETED_DEVICE_FAMILY': '2',
              'CODE_SIGN_IDENTITY': 'iPhone Developer',
              'IPHONEOS_DEPLOYMENT_TARGET': '6.1',
              'ARCHS': '$(ARCHS_STANDARD_32_BIT)',
              'CLANG_WARN_CXX0X_EXTENSIONS': 'NO',
            },
          } ],
        ],
      }, {
        'conditions': [
          ['OS=="linux"', {
            'libraries': [
              '-L<(QT_LIB_PATH)',
              '-lQtNetwork',
              '-lQtGui',
              '-lQtXml',
              '-lQtCore',
              '-lQtDeclarative',
              '-lpthread',
              '-lrt',
              '-ldl',
            ],
          } ],
          [ 'OS=="win"', {
            'libraries': [
              '-l<(QT_LIB_PATH)/QtNetwork4',
              '-l<(QT_LIB_PATH)/QtGui4',
              '-l<(QT_LIB_PATH)/QtXml4',
              '-l<(QT_LIB_PATH)/QtCore4',
              '-l<(QT_LIB_PATH)/QtDeclarative4',
              '-luser32.lib',
              '-lws2_32.lib',
              '-lshell32.lib',
              '-ladvapi32.lib',
              '-lpsapi.lib',
              '-lkernel32.lib',
              '-luserenv.lib',
            ],
          } ],
          [ 'OS=="mac"', {
            'link_settings': {
              'libraries': [
                '<(QT_LIB_PATH)/QtGui.framework',
                '<(QT_LIB_PATH)/QtCore.framework',
                '<(QT_LIB_PATH)/QtNetwork.framework',
                '<(QT_LIB_PATH)/QtDeclarative.framework',
                '<(QT_LIB_PATH)/QtXml.framework',
                '$(SDKROOT)/System/Library/Frameworks/Foundation.framework',
                '$(SDKROOT)/System/Library/Frameworks/CoreFoundation.framework',
                '$(SDKROOT)/System/Library/Frameworks/ApplicationServices.framework',
                '$(SDKROOT)/System/Library/Frameworks/Security.framework',
              ],
              'xcode_settings': {
                'FRAMEWORK_SEARCH_PATHS': '<(QT_LIB_PATH)',
              },
            },
          } ],
        ],
      } ],
    ], # conditions

  }, # target_defaults

  'targets': [
    {
      'target_name': 'WebDriver_setup',
      'type': 'static_library',
      'standalone_static_library': 1,

      'sources': [
        'inc/setup/session_notifier.h',
        'src/setup/session_notifier.cc',
        '<(INTERMEDIATE_DIR)/moc_session_notifier.cc',
        'src/setup/plugin_session_lifecycle_actions.cc',
        'src/setup/webdriver_setup.h',
        'src/setup/webdriver_setup.cc',
        '<(INTERMEDIATE_DIR)/moc_webdriver_setup.cc',
      ],
      'dependencies': [
        'base.gyp:chromium_base',
        'wd_core.gyp:WebDriver_core',
        'wd_ext_qt.gyp:WebDriver_extension_qt_base',
        'wd_ext_qt.gyp:WebDriver_extension_qt_web',
      ],
    } , {
      'target_name': 'WebDriver_setup_shared',
      'type': 'shared_library',

      'product_name': 'WebDriver_setup',

      'dependencies': [
        'WebDriver_setup',
        'base.gyp:chromium_base',
        'wd_core.gyp:WebDriver_core',
        'wd_ext_qt.gyp:WebDriver_extension_qt_base',
        'wd_ext_qt.gyp:WebDriver_extension_qt_web',
      ],
    }
  ],
}
