#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "Log.h"

#ifdef Q_OS_WIN
#include "../dependency/win32/libuv/include/uv.h"
#else
#include <uv.h>
#endif

class TcpSocket
{
  typedef int SocketDescriptor;
  typedef struct {
    uv_write_t req;
    uv_buf_t buf;
  } write_req_t;

public:
  TcpSocket(uv_loop_t *loop);

  void start();
  void close();
  void connect(const char* addr, const int &port);
  static void write(const uv_buf_t *data);

  void setKeepAlive(const bool &enabled, const int &delay);

  uv_tcp_t* getSocket();
  static int getSocketDescriptor();


private:
  static uv_tcp_t* tcp_socket;
  static uv_loop_t* uv_loop;

  static void read(uv_stream_t *handle, ssize_t nread, const uv_buf_t *buf);
  static void writeCb(uv_write_t *handle, int status);
  static void allocBuffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf);
  static void freeWriteReq(uv_write_t *handle);


  static int getSocketDescriptor(uv_handle_t *handle);
};

#endif // TCPSOCKET_H
