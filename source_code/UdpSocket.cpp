#include "UdpSocket.h"

bool UdpSocket::keep_alive;
uv_udp_t* UdpSocket::udp_socket;
uv_loop_t* UdpSocket::uv_loop;


UdpSocket::UdpSocket(const char *ipAddr, const int &port, const bool keepAlive, uv_loop_t *loop)
{
  uv_loop = loop;
  keep_alive = keepAlive;
  struct sockaddr_in *udpAddr = (sockaddr_in*)malloc(sizeof(sockaddr_in));
  uv_ip4_addr(ipAddr, port, udpAddr);
  udp_socket = (uv_udp_t*) malloc(sizeof(uv_udp_t));
  uv_udp_init(loop, udp_socket);
  uv_udp_bind(udp_socket, (const struct sockaddr*) udpAddr, UV_UDP_REUSEADDR);
  uv_udp_recv_start(udp_socket, allocBuffer, read);
  uv_udp_set_broadcast(udp_socket, 1);
}

void UdpSocket::write(const char *ipAddr, const int &port, const uv_buf_t *buf)
{
  uv_udp_send_t *req = (uv_udp_send_t*)malloc(sizeof(uv_udp_send_t));

  //  uv_buf_t msg = uv_buf_init(buf->base, buf->len);
  struct sockaddr_in addr;
  uv_ip4_addr(ipAddr, port, &addr);
  uv_udp_send(req, udp_socket, buf, 1, (const struct sockaddr *)&addr, writeCb);

//  Log::net(Log::Normal, "UvServer::sendTextMessage()", "message sent");
}

void UdpSocket::read(uv_udp_t *handle, ssize_t nread, const uv_buf_t *buf, const sockaddr *addr, unsigned flags)
{
  /// The receive callback will be called with nread == 0 and addr == NULL when there is nothing to read,
  /// and with nread == 0 and addr != NULL when an empty UDP packet is received.
  if(nread != 0) //addr sometimes is a nullptr
    {
      if(addr != NULL)
        {
          char senderAddr[17] = { 0 };
          uv_ip4_name((const struct sockaddr_in*)addr, senderAddr, 16);
//          Log::net(Log::Normal, "UdpSocket::udpReadCb()", QString("Recv from %1").arg(senderAddr));

//          uv_buf_t buffer = uv_buf_init(buf->base, nread);
          /// Do callback or what ever
        }
    }
  else
    {
      if(addr != NULL)
        {
          Log::net(Log::Normal, "UdpSocket::udpReadCb()", "Empty Packet Received...");
        }
      if(!keep_alive)
        {
          uv_close((uv_handle_t*) handle, NULL);
        }
    }

  free(buf->base);
  return;
}

void UdpSocket::writeCb(uv_udp_send_t *req, int status)
{
  free(req);

}

void UdpSocket::allocBuffer(uv_handle_t *handle, size_t suggestedSize, uv_buf_t *buf)
{
  buf->base = (char*) malloc(suggestedSize);
  buf->len = suggestedSize;
}


