import pytest
from api.swapi_client import SWAPIClient

@pytest.fixture
def api_client():
    """
    Fixture that instantiates and supplies the SWAPIClient instance.
    This runs automatically before each test that requests 'api_client'.
    """
    return SWAPIClient()
