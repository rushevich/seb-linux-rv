set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR riscv64)

# Native compilation on Debian Sid riscv64 (no explicit cross-prefix).
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=rv64gc -mabi=lp64d")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=rv64gc -mabi=lp64d")

# Hardening defaults; can be overridden by the user/toolchain environment.
add_compile_options(-fstack-protector-strong)
add_compile_definitions(_FORTIFY_SOURCE=3)
add_link_options(-Wl,-z,relro -Wl,-z,now)

