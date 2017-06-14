import socket

def create_server_socket(host,port):
    # �\�P�b�g�f�B�X�N���v�^�𐶐�
	server_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	
    # �\�P�b�g�I�v�V�����Ń\�P�b�g�̍ė��p�t���O��ON�ɐݒ�
    # ON�ɂ��Ă��Ȃ��ƃN���C�A���g�ƒʐM�r���Œ��f�����ꍇ�����A�h���X�ƃ|�[�g�Ńo�C���h�ł��Ȃ��Ȃ�܂�
	server_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    
	# �\�P�b�g�Ƀ|�[�g�ԍ����o�C���h
	server_sock.bind((host, port))
    
	# �A�N�Z�X�o�b�N���O(�ڑ��҂��̃L���[��)���w��B
	server_sock.listen(5)
	print('Server Run Port:{}\r'.format(port))
	print('Waiting for connections...')
    
	return server_sock
	
def accept_loop(server_sock):
	print('Ready For Accept')
	client_sock, client_address = server_sock.accept()
	while True:
		rcvmsg = client_sock.recv(1024)
		print('Received -> {}'.format(rcvmsg))
		client_sock.send('HELLO') #���b�Z�[�W��Ԃ��܂�
	client_sock.close()
	return

