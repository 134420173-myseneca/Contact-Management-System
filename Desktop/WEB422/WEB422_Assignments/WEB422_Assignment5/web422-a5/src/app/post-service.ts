import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Observable } from 'rxjs';
import { BlogPost } from '../BlogPost';

const perPage = 6;

@Injectable({
    providedIn: 'root'
  })
  export class PostService {
  
    constructor(private http: HttpClient) { }
  
    // getPosts to return all posts in a specific page
    getPosts(page, tag, category): Observable<BlogPost[]> {
      let params = {
        page: page,
        perPage: perPage.toString()
      }
  
      if (tag != null || tag != undefined) {
        params["tag"] = tag;
      }
  
      if (category != null || category != undefined) {
        params["category"] = category;
      }
  
      return this.http.get<BlogPost[]>(`https://agile-temple-32173.herokuapp.com/api/posts`,{ params });
    }
  
    //getPostByID to return single post by id
    getPostByID(id): Observable<BlogPost> {
      return this.http.get<BlogPost>(`https://agile-temple-32173.herokuapp.com/api/posts/${id}`);
    }
  
    // Get categories
    getCategories(): Observable<any> {
      return this.http.get<any>(`https://agile-temple-32173.herokuapp.com/api/categories`);
    }
  
    // Get tags
    getTags(): Observable<string[]> {
      return this.http.get<string[]>(`https://agile-temple-32173.herokuapp.com/api/tags`);
    }
  
    

  // assignment 6 -- GetAllPosts //
  getAllPosts(): Observable<BlogPost[]> {
    return this.http.get<BlogPost[]>(`https://agile-temple-32173.herokuapp.com/api/posts?page=1&perPage=${Number.MAX_SAFE_INTEGER.toString()}`);
  }

  // assignment 6 -- NewPost //
  newPost(data: BlogPost): Observable<any>{
    return this.http.post<any>(`https://agile-temple-32173.herokuapp.com/api/posts`, data);
  }

  // assignment 6 -- UpdatePostById //
  updatePostById(id: string, data: BlogPost): Observable<any>{
    return this.http.put<any>(`https://agile-temple-32173.herokuapp.com/api/posts/${id}`, data);
  }

  // assignment 6 -- DeletePostById //
  deletePostById(id: string): Observable<any> {
    return this.http.delete<any>(`https://agile-temple-32173.herokuapp.com/api/posts/${id}`);
  }
}



  
  
