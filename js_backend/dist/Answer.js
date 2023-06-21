import { v4 } from "uuid";
export default class Answer {
    id = v4();
    answerText;
    answerers = [];
    constructor(obj) {
        this.answerText = obj.answerText;
        if (obj.id != null) {
            this.id = obj.id;
        }
        if (obj.answerers != null) {
            this.answerers = obj.answerers;
        }
    }
}
//# sourceMappingURL=Answer.js.map