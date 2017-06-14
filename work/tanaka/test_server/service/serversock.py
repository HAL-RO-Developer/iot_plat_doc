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
		while True:
			# クライアントからの接続を待ち受ける
			clint_sock, (client_address, client_port) = Serversock.server_sock.accept()
			print('New client: {0}:{1}'.format(client_address, client_port))
			try:
				message = client_sock.recv(1024)
				print('Recv: {}'.format(message))
			except OSError:
				break
			client_sock.send('HELLO') #メッセージを返します
			print('Send: HELLO')
		client_sock.close()
		
		return

