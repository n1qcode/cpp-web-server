project(
    'cpp-web-server',
    'cpp',
    version: '0.0.1',
    default_options: [
        'warning_level=3',
        'cpp_std=c++20',
        'default_library=static',
    ],
)

deps = [
    dependency(
        'boost',
        modules: ['thread', 'chrono', 'json'],
        static: true,
    ),
]

executable(
    'cpp-web-server',
    ['src/main.cpp', 'src/cpp_web_server.cpp'],
    install: true,
    dependencies: deps,
)