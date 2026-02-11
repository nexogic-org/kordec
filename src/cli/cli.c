#include "cli.h"
#include "../const.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>

static void print_error(const char *operation, const char *path, int err) {
    fprintf(stderr, "\033[1;31mError %s %s: %s\033[0m\n", operation, path, strerror(err));
}

void kordec_cli_parser(int argc, char *argv[]) {
    if (argc == 1) {
        printf(
        "*  Welcome to Kordec!\n"
        "*  Kordec is a tool for managing Go source code.\n"
        "*  Kordec Version: %s\n"
        "*  Copyright (c) 2026 Nexogic. Released under MIT License.\n"
        "\n"
        "* Usage:\n\n"
        "  kordec <command> [arguments]\n"
        "\n"
        "* The commands are:\n\n"
        "  run        compile and run Kordec program.\n"
        "  build      package your Kordec code into a .kar archive format.\n"
        "  version    print Kordec version.\n"
        "  help       for more information about a command.\n"
        "  init       initialize a Kordec project.\n"
        "  compile    compile your code, but do not execute it.\n", KORDEC_VERSION);
        return;
    }

    if (0 == strcmp("version", argv[1])) {
        printf("Kordec Version: %s\n", KORDEC_VERSION);
    } else if (0 == strcmp("help", argv[1])) {
        printf(
        "*  Welcome to Kordec!\n"
        "*  Kordec is a tool for managing Go source code.\n"
        "*  Kordec Version: %s\n"
        "*  Copyright (c) 2026 Nexogic. Released under MIT License.\n"
        "\n"
        "* Usage:\n\n"
        "  kordec <command> [arguments]\n"
        "\n"
        "* The commands are:\n\n"
        "  run        compile and run Kordec program.\n"
        "  build      package your Kordec code into a .kar archive format.\n"
        "  version    print Kordec version.\n"
        "  help       for more information about a command.\n"
        "  init       initialize a Kordec project.\n"
        "  compile    compile your code, but do not execute it.\n"
        "  install    download a Kordec package to your project.\n"
        "  uninstall  uninstall a Kordec package from your project.", KORDEC_VERSION);
    } else if (0 == strcmp("init", argv[1])) {
        if (argc > 2) {
            char buf[PATH_MAX];
            // 获取当前工作目录
            if (getcwd(buf, sizeof(buf)) == NULL) {
                perror("\033[1;31mFailed to get current working directory\033[0m");
                return;
            }

            char root_dir[PATH_MAX];
            // 使用 snprintf 确保路径拼接安全，检查返回值防止缓冲区溢出
            int ret = snprintf(root_dir, sizeof(root_dir), "%s/%s", buf, argv[2]);
            if (ret < 0 || ret >= sizeof(root_dir)) {
                fprintf(stderr, "\033[1;31mPath too long: %s/%s\033[0m\n", buf, argv[2]);
                return;
            }

            // 创建根目录
            if (mkdir(root_dir) == -1) {
                if (errno != EEXIST) {
                    print_error("creating directory", root_dir, errno);
                    return;
                }
                fprintf(stderr, "\033[1;33mWarning: Directory %s already exists\033[0m\n", root_dir);
            }

            // 创建 kordec_modules 目录
            char kordec_modules_dir[PATH_MAX];
            ret = snprintf(kordec_modules_dir, sizeof(kordec_modules_dir), "%s/kordec_modules", root_dir);
            if (ret < 0 || ret >= sizeof(kordec_modules_dir)) {
                fprintf(stderr, "\033[1;31mPath too long: %s/kordec_modules\033[0m\n", root_dir);
                return;
            }
            if (mkdir(kordec_modules_dir) == -1) {
                if (errno != EEXIST) {
                    print_error("creating directory", kordec_modules_dir, errno);
                    return;
                }
            }

            char kordec_pkg_path[PATH_MAX];
            ret = snprintf(kordec_pkg_path, sizeof(kordec_pkg_path), "%s/kordec.pkg", kordec_modules_dir);
            if (ret < 0 || ret >= sizeof(kordec_pkg_path)) {
                fprintf(stderr, "\033[1;31mPath too long: %s/kordec.pkg\033[0m\n", kordec_modules_dir);
                return;
            }
            FILE *kordec_pkg = fopen(kordec_pkg_path, "w");
            if (kordec_pkg == NULL) {
                print_error("creating file", kordec_pkg_path, errno);
                return;
            }
            fclose(kordec_pkg);

            // 创建 src 目录
            char src_dir[PATH_MAX];
            ret = snprintf(src_dir, sizeof(src_dir), "%s/src", root_dir);
            if (ret < 0 || ret >= sizeof(src_dir)) {
                fprintf(stderr, "\033[1;31mPath too long: %s/src\033[0m\n", root_dir);
                return;
            }
            if (mkdir(src_dir) == -1) {
                if (errno != EEXIST) {
                    print_error("creating directory", src_dir, errno);
                    return;
                }
            }

            char main_kd_path[PATH_MAX];
            ret = snprintf(main_kd_path, sizeof(main_kd_path), "%s/src/main.kd", root_dir);
            if (ret < 0 || ret >= sizeof(main_kd_path)) {
                fprintf(stderr, "\033[1;31mPath too long: %s/src/main.kd\033[0m\n", root_dir);
                return;
            }
            FILE *main_kd = fopen(main_kd_path, "w");
            if (main_kd == NULL) {
                print_error("creating file", main_kd_path, errno);
                return;
            }
            // 写入指定的 main.kd 内容
            fprintf(main_kd, "import console;\n\n");
            fprintf(main_kd, "class test {\n");
            fprintf(main_kd, "    public static void main() {\n");
            fprintf(main_kd, "        console.println(\"Hello, World!\");\n");
            fprintf(main_kd, "    }\n");
            fprintf(main_kd, "}\n");
            fclose(main_kd);
            char project_json_path[PATH_MAX];
            ret = snprintf(project_json_path, sizeof(project_json_path), "%s/project.json", root_dir);
            if (ret < 0 || ret >= sizeof(project_json_path)) {
                fprintf(stderr, "\033[1;31mPath too long: %s/project.json\033[0m\n", root_dir);
                return;
            }
            FILE *project_json = fopen(project_json_path, "w");
            if (project_json == NULL) {
                print_error("creating file", project_json_path, errno);
                return;
            }
            // 写入 JSON 格式的配置
            fprintf(project_json, "{\n");
            fprintf(project_json, "    \"name\": \"%s\",\n", argv[2]);
            fprintf(project_json, "    \"version\": \"0.1.0\"\n");
            fprintf(project_json, "}\n");
            fclose(project_json);

            printf("\033[1;32mProject initialized successfully in %s\033[0m\n", root_dir);
        } else {
            printf("\033[1;37mkordec init\033[0m: \033[31mA parameter is missing (project name)\033[0m\n");
            printf("Usage: kordec init <project-name>\n");
        }
    } else {
        fprintf(stderr, "\033[1;31mUnknown command: %s\033[0m\n", argv[1]);
        fprintf(stderr, "Run 'kordec help' for usage information.\n");
    }
}