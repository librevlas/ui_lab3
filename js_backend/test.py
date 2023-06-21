import unittest
import requests
import json

class TestAPI(unittest.TestCase):
    BASE_URL = 'http://localhost:3000'  # Assuming API is running on localhost port 3000

    def test_users(self):

        # Add a new user
        response = requests.post(f'{self.BASE_URL}/users', json={
            'login': 'testUser2',
            'password': 'testPassword',
            'birthdate': '2000-01-01'
        })
        self.assertEqual(response.status_code, 201)
        
        # Add a new user
        response = requests.post(f'{self.BASE_URL}/users', json={
            'login': 'testUser',
            'password': 'testPassword',
            'birthdate': '2000-01-01'
        })
        self.assertEqual(response.status_code, 201)

        # Sign in with the new user
        response = requests.post(f'{self.BASE_URL}/users/signin', json={
            'login': 'testUser',
            'password': 'testPassword'
        })
        self.assertEqual(response.status_code, 200)

        # Remove the new user
        response = requests.delete(f'{self.BASE_URL}/users/testUser')
        self.assertEqual(response.status_code, 200)

    def test_questions(self):
        # Add a new question
        response = requests.post(f'{self.BASE_URL}/questions', json={
            'authorLogin': 'testUser',
            'questionText': 'Test question?'
        })
        self.assertEqual(response.status_code, 201)

        # Get the question id
        questionId = json.loads(response.text)['id']

        # Get all questions
        response = requests.get(f'{self.BASE_URL}/questions')
        self.assertEqual(response.status_code, 200)

        # Remove the new question
        response = requests.delete(f'{self.BASE_URL}/questions/{questionId}', json={
            'login': 'testUser'
        })
        self.assertEqual(response.status_code, 200)

    def test_answers(self):
        # Add a new question
        response = requests.post(f'{self.BASE_URL}/questions', json={
            'authorLogin': 'testUser',
            'questionText': 'Test question?'
        })
        self.assertEqual(response.status_code, 201)

        # Get the question id
        questionId = json.loads(response.text)['id']

        # Add an answer to the question
        response = requests.post(f'{self.BASE_URL}/questions/{questionId}/answers', json={
            'answerText': 'Test answer.',
            'login': 'testUser'
        })
        self.assertEqual(response.status_code, 201)

        # Upvote an answer
        answerId = json.loads(response.text)['id']
        response = requests.put(f'{self.BASE_URL}/questions/{questionId}/answers/{answerId}', json={
            'login': 'testUser2'
        })
        self.assertEqual(response.status_code, 200)

        # Remove the question and its associated answers
        response = requests.delete(f'{self.BASE_URL}/questions/{questionId}', json={
            'login': 'testUser'
        })
        self.assertEqual(response.status_code, 200)

if __name__ == '__main__':
    unittest.main()
