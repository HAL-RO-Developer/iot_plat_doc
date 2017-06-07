import argparse

def create_args(**kwargs):
	parser = argparse.ArgumentParser(description='this is ...')
	parser.add_argument('-m', action='store_const', const=True, default=False, help="...")
	#parser.add_argument('-s', help="...")
	return parser.parse_args()

args = create_args()