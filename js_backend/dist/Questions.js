import Question from "./Question.js";
export default class Questions {
    questionList = [];
    _getQuestionIndex(questionId) {
        return this.questionList.findIndex((answer) => answer.id === questionId);
    }
    addQuestion(questionObj) {
        this.questionList.push(new Question(questionObj));
    }
    getQuestion(questionId) {
        return this.questionList[this._getQuestionIndex(questionId)];
    }
    deleteQuestion(questionId) {
        this.questionList.splice(this._getQuestionIndex(questionId), 1);
    }
}
//# sourceMappingURL=Questions.js.map