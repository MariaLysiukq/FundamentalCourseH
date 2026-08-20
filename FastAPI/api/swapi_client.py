import requests
from config import BASE_URL, AUTH_TOKEN

class SWAPIClient:
    """Client class to interact with API endpoints with auth support."""
    def __init__(self, base_url: str = BASE_URL, auth_token: str = AUTH_TOKEN):
        self.base_url = base_url
        self.session = requests.Session()        
        self.session.headers.update({
            "Content-Type": "application/json",
            "Authorization": auth_token
        })


    def get_people(self, search: str = None, page: int = None):
        params = {}
        if search:
            params["search"] = search
        if page:
            params["page"] = page  
        return self.session.get(f"{self.base_url}/people/", params=params)


    def get_person_by_id(self, person_id: int):
        return self.session.get(f"{self.base_url}/people/{person_id}/")
