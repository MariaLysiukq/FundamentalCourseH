def test_get_all_people(api_client):
    """Verify that GET /people returns status 200 and a non-empty list of characters."""
    response = api_client.get_people()
    assert response.status_code == 200, f"Expected status 200, but got {response.status_code}"
    data = response.json()
    assert "results" in data, "Response body missing 'results' key"
    assert len(data["results"]) > 0, "'results' list should not be empty"


def test_get_person_by_id(api_client):
    """Verify fetching a specific character by ID (Luke Skywalker = ID 1)."""
    response = api_client.get_person_by_id(1)
    assert response.status_code == 200
    data = response.json()
    assert data["name"] == "Luke Skywalker"
    assert "height" in data
    assert "mass" in data


def test_search_person(api_client):
    """Verify filtering people using query parameters (?search=Darth Vader)."""
    response = api_client.get_people(search="Darth Vader")
    assert response.status_code == 200
    data = response.json()
    assert data["count"] == 1
    assert data["results"][0]["name"] == "Darth Vader"


def test_person_not_found(api_client):
    """Verify negative scenario: requesting an invalid ID returns 404 Not Found."""
    response = api_client.get_person_by_id(99999)
    assert response.status_code == 404
