#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define RESPONSE "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, World!"

void handle_client(int client_socket) {
    char buffer[1024];
    // 读取客户端请求（这里简单忽略请求内容）
    read(client_socket, buffer, sizeof(buffer));

    // 发送 HTTP 响应
    write(client_socket, RESPONSE, strlen(RESPONSE));

    // 关闭客户端连接
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // 创建 socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 绑定地址和端口
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // 监听端口
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // 主循环，接受客户端连接
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // 处理客户端请求
        handle_client(client_socket);
    }

    // 关闭服务器 socket（通常不会执行到这里）
    close(server_socket);
    return 0;
}
