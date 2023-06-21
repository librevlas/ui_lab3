import { v4 } from "uuid";
export default class Question {
    id = v4();
    authorLogin;
    createdDate;
    _questionText = "";
    answers = [];
    totalAnswerers = 0;
    _getAnswerIndex(answerId) {
        return this.answers.findIndex((answer) => answer.id === answerId);
    }
    constructor(obj) {
        this.authorLogin = obj.authorLogin;
        if (obj.id != null) {
            this.id = obj.id;
        }
        if (obj.questionText != null) {
            this._questionText = obj.questionText;
        }
        if (obj.answers != null) {
            this.answers = obj.answers;
        }
        if (obj.createdDate != null) {
            this.createdDate = new Date(obj.createdDate);
        }
        else {
            this.createdDate = new Date();
        }
        if (obj.totalAnswerers != null) {
            this.totalAnswerers = obj.totalAnswerers;
        }
    }
    set questionText(value) {
        this._questionText = value;
    }
    get questionText() {
        return this._questionText;
    }
    addVoteToAnswer(answerId, answererLogin) {
        const answer = this.answers[this._getAnswerIndex(answerId)];
        answer.answerers.push(answererLogin);
        this.totalAnswerers++;
    }
    isAlreadyVote(userLogin) {
        return this.answers.some((answer) => answer.answerers.findIndex((answerer) => answerer === userLogin) != -1);
    }
    findVotedAnswerId(userLogin) {
        for (const answer of this.answers) {
            const index = answer.answerers.findIndex((answerer) => answerer === userLogin);
            if (index != -1) {
                return answer.id;
            }
        }
        return "";
    }
}
//# sourceMappingURL=Question.js.map