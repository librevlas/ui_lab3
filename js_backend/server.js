// Import required modules
import express from 'express';
import bodyParser from 'body-parser';

// Import your classes
import User from './dist/User.js';
import Users from './dist/Users.js';
import Question from './dist/Question.js';
import Questions from './dist/Questions.js';
import Answer from './dist/Answer.js';

// Create new Users and Questions collections
let users = new Users();
let questions = new Questions();

// Create a new Express application
const app = express();

// Use body-parser middleware to parse JSON bodies
app.use(bodyParser.json());

// Define your API routes

// Add a new user
app.post('/users', (req, res) => {
  let newUser = new User(req.body);
  users.addUser(newUser);
  res.status(201).json(newUser);
});

// User sign in
app.post('/users/signin', (req, res) => {
  const { login, password } = req.body;
  const user = users.findByLogin(login);
  if(user && user.password === password) {
    res.status(200).json(user);
  } else {
    res.status(400).json({ message: 'Invalid login or password.' });
  }
});

// Remove user account
app.delete('/users/:login', (req, res) => {
  const user = users.findByLogin(req.params.login);
  if (user) {
    users.deleteUser(user.login);
    res.status(200).json({ message: 'User deleted successfully.' });
  } else {
    res.status(404).json({ message: 'User not found.' });
  }
});

// Get all questions
app.get('/questions', (req, res) => {
  res.json(questions.questionList);
});

// Add a new question
app.post('/questions', (req, res) => {
  let newQuestion = new Question(req.body);
  questions.addQuestion(newQuestion);
  res.status(201).json(newQuestion);
});

// Remove question by its author
app.delete('/questions/:id', (req, res) => {
  const question = questions.getQuestion(req.params.id);
  if(question && question.authorLogin === req.body.login) {
    questions.deleteQuestion(question.id);
    res.status(200).json({ message: 'Question deleted successfully.' });
  } else {
    res.status(400).json({ message: 'Cannot delete question.' });
  }
});

// Add an answer to a question
app.post('/questions/:id/answers', (req, res) => {
  const question = questions.getQuestion(req.params.id);
  if(question) {
    const answer = new Answer({ answerText: req.body.answerText, answerers: [req.body.login] });
    question.answers.push(answer);
    res.status(201).json(answer);
  } else {
    res.status(404).json({ message: 'Question not found.' });
  }
});

// Upvote an answer
app.put('/questions/:questionId/answers/:answerId', (req, res) => {
  const question = questions.getQuestion(req.params.questionId);
  if(question) {
    const answer = question.answers.find(answer => answer.id === req.params.answerId);
    if(answer && !answer.answerers.includes(req.body.login)) {
      answer.answerers.push(req.body.login);
      res.status(200).json(answer);
    } else {
      res.status(400).json({ message: 'Cannot upvote the answer.' });
    }
  } else {
    res.status(404).json({ message: 'Question not found.' });
  }
});

// Start the server
const port = process.env.PORT ||3000;
app.listen(port, () => {
  console.log(`Server is listening on port ${port}`);
});
