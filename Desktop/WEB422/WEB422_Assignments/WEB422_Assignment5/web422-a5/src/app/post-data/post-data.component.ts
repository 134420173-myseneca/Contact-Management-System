import { Component, OnInit, OnDestroy } from '@angular/core';
import { PostService } from '../post-service';
import { ActivatedRoute } from '@angular/router';
import { BlogPost } from '../../BlogPost';

@Component({
  selector: 'app-post-data',
  templateUrl: './post-data.component.html',
  styleUrls: ['./post-data.component.css']
})


export class PostDataComponent implements OnInit, OnDestroy {

  post: BlogPost;
  querySub: any;
  commentName: string;
  commentText: string;

  constructor(private _post: PostService, private route: ActivatedRoute) { }

  ngOnInit(): void {
    this.querySub = this.route.params.subscribe(params =>{
      //TODO: Get post by Id params['id'] and store the result in this.post
      this._post.getPostByID(params['id']).subscribe(_post => {
        this.post = _post,
        this.post.views++,
        this._post.updatePostById(this.post._id, this.post).subscribe();
      });
    });
  }

  submitComment(): void{
    this.post.comments.push({
      author: this.commentName,
      comment: this.commentText,
      date: new Date().toLocaleDateString()
    })

    this._post.updatePostById(this.post._id, this.post).subscribe(() => {
      this.commentName = '';
      this.commentText = '';
    })
  }

  ngOnDestroy(): void {
    if(this.querySub) this.querySub.unsubscribe();
  }
}
