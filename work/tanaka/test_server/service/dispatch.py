from controller.main_controller import MainController

class Dispatch:
		
	def __init__(self, args):
		self.args = args

	def run(self):
		print(self.args.m)
		if self.args.m:
			MainController.hello()
		#print(self.args.s)
		