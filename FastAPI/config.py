import os
from dotenv import load_dotenv


load_dotenv()
BASE_URL = os.getenv("BASE_URL", "https://swapi.dev/api")
AUTH_TOKEN = os.getenv("AUTH_TOKEN", "fake_token_maria")
