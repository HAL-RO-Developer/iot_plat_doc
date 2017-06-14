from service.serversock import create_server_socket 
from service.serversock import accept_loop 

class dispatch:
		
	def __init__(self, args):
		self.args = args

	def run(self):
		print(self.args.m)
		if self.args.m:
			server_sock = create_server_socket('127.0.0.1',4000)
			accept_loop(server_sock)
		#print(self.args.s)
		