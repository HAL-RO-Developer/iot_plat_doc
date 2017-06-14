import socket

class Serversock:
	server_sock = None

	@staticmethod
	def create_server_socket(host,port):
		# ソケットディスクリプタを生成
		Serversock.server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		
		# ソケットオプションでソケットの再利用フラグをONに設定
		# ONにしていないとクライアントと通信途中で中断した場合同じアドレスとポートでバインドできなくなります
		Serversock.server_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
		
		# ソケットにポート番号をバインド
		Serversock.server_sock.bind((host, port))
		
		# アクセスバックログ(接続待ちのキュー数)を指定。
		Serversock.server_sock.listen(5)
		print('Server Run Port:{}\r'.format(port))
		print('Waiting for connections...')

		return
		
	@staticmethod
	def accept_loop():
		print('Ready For Accept')
		client_sock, client_address = Serversock.server_sock.accept()
		while True:
			rcvmsg = client_sock.recv(1024)
			print('Received -> {}'.format(rcvmsg))
			client_sock.send('HELLO') #メッセージを返します
		client_sock.close()
		return

